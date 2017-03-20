/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_64.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:18:35 by nle-bret          #+#    #+#             */
/*   Updated: 2017/03/18 18:18:36 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int		compare_64(t_process *process,
	t_node_symbol_64 *ns1, t_node_symbol_64 *ns2)
{
	int		cmp;

	if (process->flag & FLAG_V)
	{
		if (ns1->nl->n_value == 0 && ns2->nl->n_value > 0)
			return (-1);
		return (ns1->nl->n_value - ns2->nl->n_value);
	}
	cmp = ft_strcmp(ns1->output, ns2->output);
	if (cmp == 0)
		cmp = ns1->nl->n_value - ns2->nl->n_value;
	return (cmp);
}

void	insertion_sort_symbol_64(t_process *process, t_node_symbol_64 *ns)
{
	t_link				*node;
	t_node_symbol_64	*ns2;

	node = process->list_symbol.head;
	if (node != NULL && !(process->flag & FLAG_P))
	{
		while (node)
		{
			ns2 = PTR_NODE(node, t_node_symbol_64, link);
			if (compare_64(process, ns, ns2) < 0)
			{
				ft_list_push_before_node(&process->list_symbol,
				&ns2->link, &ns->link);
				return ;
			}
			node = node->next;
		}
	}
	ft_list_push_back(&process->list_symbol, &ns->link);
}

void	sort_symbol_64(t_process *process)
{
	uint32_t			i;
	char				*string_table;
	struct nlist_64		*array;
	char				*output;
	t_node_symbol_64	*ns;

	array = (void*)process->ptr + process->sym->symoff;
	string_table = (void*)process->ptr + process->sym->stroff;
	i = 0;
	while (i < process->sym->nsyms)
	{
		if (((array[i].n_type & N_TYPE) == N_SECT &&
			array[i].n_sect >= 1 && array[i].n_un.n_strx > 1)
			|| ((array[i].n_type & N_STAB) == N_UNDF))
		{
			output = (string_table + array[i].n_un.n_strx);
			ns = make_node_symbol_64(process, output, &array[i]);
			insertion_sort_symbol_64(process, ns);
		}
		i++;
	}
}
