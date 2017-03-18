/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_32.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 17:04:28 by nle-bret          #+#    #+#             */
/*   Updated: 2017/03/18 17:04:29 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void				print_sym_value_32(uint32_t sym_value, char type)
{
	char	*str;
	int		align;
	char	t;

	t = ft_toupper(type);
	if (t == 'T' || t == 'B' || t == 'D' || t == 'S' ||
		t == 'I' || t == 'A' || t == 'C')
	{
		str = ulltoa_base(sym_value, 16);
		align = 8 - ft_strlen(str);
		while (align--)
			write(1, "0", 1);
		ft_putstr(str);
		free(str);
	}
	else
		write(1, "        ", 8);
}

void				print_32(t_process *process)
{
	t_link				*node;
	t_node_symbol_32	*ns;

	node = process->list_symbol.head;
	if (process->nb_file > 1 && process->is_lib == 0)
	{
		ft_putchar('\n');
		ft_putstr(process->file_name);
		ft_putstr(":\n");
	}
	while (node)
	{
		ns = PTR_NODE(node, t_node_symbol_32, link);
		ns->nl->n_value = convert_uint32(process, ns->nl->n_value);
		print_sym_value_32(ns->nl->n_value, ns->c);
		ft_putchar(' ');
		ft_putchar(ns->c);
		ft_putchar(' ');
		ft_putstr(ns->output);
		ft_putchar('\n');
		node = node->next;
	}
}

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
