/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 17:04:13 by nle-bret          #+#    #+#             */
/*   Updated: 2017/03/18 17:04:14 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

void			print_byte(unsigned char byte)
{
	static char	hexa[16] = "0123456789abcdef";

	write(1, &hexa[byte >> 4], 1);
	write(1, &hexa[byte & 15], 1);
}

void				print_addr(uint64_t addr)
{
	char	*str;
	int		align;

	str = ulltoa_base(addr, 16);
	align = 16 - ft_strlen(str);
	while (align--)
		write(1, "0", 1);
	ft_putstr(str);
	free(str);
}

void			print_section(t_process *process, struct section_64 *section)
{
	void	*ptr;
	void	*ptr_end;
	int 	i;

	if (ft_strcmp(section->sectname, SECT_TEXT) == 0)
	{
		ptr = process->ptr_start + section->offset;
		ptr_end = ptr + section->size;
		i = 0;
		ft_putstr("Contents of (__TEXT,__text) section");
		while (ptr < ptr_end)
		{
			if (i % 16 == 0)
			{
				ft_putchar('\n');
				print_addr(section->addr);
				ft_putchar('\t');
				section->addr += 16;
			}
			print_byte(*(unsigned char *)ptr);
			ft_putchar(' ');
			ptr++;
			i++;
		}
	}
}

static void		loop_section(t_process *process, struct load_command *lc)
{
	uint32_t					j;
	struct segment_command_64	*sg;
	struct section_64			*s;

	j = 0;
	sg = (struct segment_command_64 *)lc;
	s = (struct section_64 *)((char *)sg + sizeof(struct segment_command_64));

	while (j < sg->nsects)
	{
		print_section(process, s + j);
		j++;
	}
}

void			find_segment_64(t_process *process)
{
	uint32_t					i;
	struct load_command			*lc;

	i = 0;
	lc = process->load_command;
	ft_putstr(process->file_name);
	ft_putstr(":\n");
	while (i < process->header_64->ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
			loop_section(process, lc);
		i++;
		lc = (void*)lc + lc->cmdsize;
	}
	ft_putchar('\n');
}

void			handle_64(t_process *process)
{
	int						ncmds;
	int						i;
	struct load_command		*lc;

	process->header_64 = (struct mach_header_64*)process->ptr;
	ncmds = process->header_64->ncmds;
	process->load_command = (void*)process->ptr + sizeof(*process->header_64);
	lc = process->load_command;
	i = 0;
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
			process->sym = (struct symtab_command*)lc;
		else if (lc->cmd == LC_SEGMENT_64)
			process->nsects += ((struct segment_command_64 *)lc)->nsects;
		i++;
		lc = (void*)lc + lc->cmdsize;
	}
	if (process->nsects > 0)
		find_segment_64(process);
}
