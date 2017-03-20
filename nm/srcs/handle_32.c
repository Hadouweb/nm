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

#include "ft_nm.h"

t_node_symbol_32	*make_node_symbol_32(t_process *process,
	char *output, struct nlist *nl)
{
	t_node_symbol_32	*ns;

	ns = (t_node_symbol_32*)malloc(sizeof(t_node_symbol_32));
	ns->nl = nl;
	ns->c = get_type_32(process, nl);
	ns->output = output;
	ns->link.next = NULL;
	ns->link.prev = NULL;
	return (ns);
}

void				add_section_32_subfunc(t_process *process,
	int *k, struct load_command *lc)
{
	uint32_t					j;
	uint32_t					nsects;
	struct segment_command		*sg;
	struct section				*s;

	j = 0;
	sg = (struct segment_command *)lc;
	nsects = convert_uint32(process, sg->nsects);
	s = (struct section *)((char *)sg + sizeof(struct segment_command));
	while (j < nsects)
	{
		process->section_32[*k] = s + j;
		add_memory_type(process, process->section_32[*k]->sectname, *k);
		(*k)++;
		j++;
	}
}

void				add_section_32(t_process *process)
{
	uint32_t					i;
	int							k;
	struct load_command			*lc;

	i = 0;
	k = 0;
	process->section_32 = (struct section **)
			malloc(sizeof(struct section *) * process->nsects);
	lc = process->load_command;
	while (i < process->header_32->ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
			add_section_32_subfunc(process, &k, lc);
		i++;
		lc = (void*)lc + lc->cmdsize;
	}
}

static void			handle_32_sub_func(t_process *process,
	struct symtab_command *lc)
{
	if (lc->cmd == LC_SYMTAB)
		process->sym = convert_symtab(process, lc);
	else if (lc->cmd == LC_SEGMENT)
		process->nsects += convert_uint32(process,
		((struct segment_command *)lc)->nsects);
}

void				handle_32(t_process *process, char mode)
{
	int						ncmds;
	int						i;
	struct load_command		*lc;

	process->is_big_endian = mode;
	process->header_32 = (struct mach_header*)process->ptr;
	ncmds = convert_uint32(process, process->header_32->ncmds);
	process->load_command = (void*)process->ptr + sizeof(*process->header_32);
	lc = convert_load_cmd(process, process->load_command);
	i = 0;
	while (i < ncmds)
	{
		handle_32_sub_func(process, (struct symtab_command *)lc);
		i++;
		lc = convert_load_cmd(process, (void*)lc + lc->cmdsize);
	}
	if (process->nsects > 0)
		add_section_32(process);
	if (process->sym)
		sort_symbol_32(process);
	print_32(process);
	clear_process(process);
}
