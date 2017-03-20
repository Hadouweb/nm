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

#include "ft_nm.h"

t_node_symbol_64	*make_node_symbol_64(t_process *process,
	char *output, struct nlist_64 *nl)
{
	t_node_symbol_64	*ns;

	ns = (t_node_symbol_64*)malloc(sizeof(t_node_symbol_64));
	ns->nl = nl;
	ns->c = get_type_64(process, nl);
	ns->output = output;
	ns->link.next = NULL;
	ns->link.prev = NULL;
	return (ns);
}

void				add_section_64_subfunc(t_process *process,
	int *k, struct load_command *lc)
{
	uint32_t					j;
	struct segment_command_64	*sg;
	struct section_64			*s;

	j = 0;
	sg = (struct segment_command_64 *)lc;
	s = (struct section_64 *)((char *)sg + sizeof(struct segment_command_64));
	while (j < sg->nsects)
	{
		process->section_64[*k] = s + j;
		add_memory_type(process, process->section_64[*k]->sectname, *k);
		(*k)++;
		j++;
	}
}

void				add_section_64(t_process *process)
{
	uint32_t					i;
	int							k;
	struct load_command			*lc;

	i = 0;
	k = 0;
	process->section_64 = (struct section_64 **)
			malloc(sizeof(struct section_64 *) * process->nsects);
	lc = process->load_command;
	while (i < process->header_64->ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
			add_section_64_subfunc(process, &k, lc);
		i++;
		lc = (void*)lc + lc->cmdsize;
	}
}

void				handle_64(t_process *process)
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
		add_section_64(process);
	if (process->sym)
		sort_symbol_64(process);
	clear_process(process);
}
