/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 17:04:06 by nle-bret          #+#    #+#             */
/*   Updated: 2017/03/18 17:04:07 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

void			print_section_32(t_process *process, struct section *section)
{
	void		*ptr;
	void		*ptr_end;
	uint32_t	i;

	if (ft_strcmp(section->sectname, SECT_TEXT) == 0)
	{
		section->offset = convert_uint32(process, section->offset);
		section->size = convert_uint32(process, section->size);
		ptr = process->ptr + section->offset;
		ptr_end = ptr + section->size;
		i = 0;
		ft_putstr("Contents of (__TEXT,__text) section\n");
		section->addr = convert_uint32(process, section->addr);
		while (ptr < ptr_end && i < section->size)
		{
			if (i % 16 == 0)
			{
				if (i > 0)
				{
					ft_putchar(' ');
					ft_putchar('\n');
				}
				print_addr_32(section->addr);
				ft_putchar('\t');
				section->addr += 16;
			}
			else if (i % 4 == 0 && process->is_big_endian == 1)
				ft_putchar(' ');
			else if (process->is_big_endian == 0)
				ft_putchar(' ');
			print_byte(*(unsigned char *)ptr);
			ptr++;
			i++;
		}
		ft_putstr(" \n");
	}
}

static void		loop_section_32(t_process *process, struct load_command *lc)
{
	uint32_t					j;
	struct segment_command		*sg;
	struct section				*s;
	uint32_t 					nsects;

	j = 0;
	sg = (struct segment_command *)lc;
	s = (struct section *)((char *)sg + sizeof(struct segment_command));
	nsects = convert_uint32(process, sg->nsects);
	while (j < nsects)
	{
		print_section_32(process, s + j);
		j++;
	}
}

void			find_segment_32(t_process *process)
{
	uint32_t					i;
	struct load_command			*lc;

	i = 0;
	if (process->arch[2].arch == NULL && process->is_lib == 0)
	{
		ft_putstr(process->file_name);
		ft_putstr(":\n");
	}
	lc = process->load_command;
	while (i < process->header_32->ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
			loop_section_32(process, lc);
		i++;
		lc = (void*)lc + lc->cmdsize;
	}
}

void			handle_32(t_process *process, char mode)
{
	int						ncmds;
	int						i;
	struct load_command		*lc;

	//printf("handle_32 %s\n", process->file_name);
	process->is_big_endian = mode;
	//printf("---------> mode: %d\n", mode);
	process->header_32 = (struct mach_header*)process->ptr;
	ncmds = convert_uint32(process, process->header_32->ncmds);
	process->load_command = (void*)process->ptr + sizeof(*process->header_32);
	lc = convert_load_cmd(process, process->load_command);
	i = 0;
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
			process->sym = convert_symtab(process, (struct symtab_command*)lc);
		else if (lc->cmd == LC_SEGMENT)
			process->nsects += convert_uint32(process,
			((struct segment_command *)lc)->nsects);
		i++;
		lc = convert_load_cmd(process, (void*)lc + lc->cmdsize);
	}
	if (process->nsects > 0)
		find_segment_32(process);
	clear_process(process);
}
