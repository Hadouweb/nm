/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_64.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 17:04:32 by nle-bret          #+#    #+#             */
/*   Updated: 2017/03/18 17:04:33 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void				print_sym_value_64(uint64_t sym_value, char type)
{
	char	*str;
	int		align;
	char	t;

	t = ft_toupper(type);
	if (t == 'T' || t == 'B' || t == 'D' || t == 'S' ||
		t == 'I' || t == 'A' || t == 'C')
	{
		str = ulltoa_base(sym_value, 16);
		align = 16 - ft_strlen(str);
		while (align--)
			write(1, "0", 1);
		ft_putstr(str);
		free(str);
	}
	else
		write(1, "                ", 16);
}

void				print_64_regular(t_node_symbol_64 *ns)
{
	print_sym_value_64(ns->nl->n_value, ns->c);
	ft_putchar(' ');
	ft_putchar(ns->c);
	ft_putchar(' ');
	ft_putstr(ns->output);
	ft_putchar('\n');
}

void				print_64_undefined_only(t_node_symbol_64 *ns)
{
	if (ns->c == 'U')
	{
		ft_putstr(ns->output);
		ft_putchar('\n');
	}
}

void				print_64_reverse(t_process *process)
{
	t_link				*node;
	t_node_symbol_64	*ns;

	node = process->list_symbol.tail;
	if (process->nb_file > 1 && process->is_lib == 0)
	{
		ft_putchar('\n');
		ft_putstr(process->file_name);
		ft_putstr(":\n");
	}
	while (node)
	{
		ns = PTR_NODE(node, t_node_symbol_64, link);
		if (process->flag & FLAG_U_MIN)
			print_64_undefined_only(ns);
		else if (process->flag & FLAG_U_MAX && ns->c != 'U')
			print_64_regular(ns);
		else if (!(process->flag & FLAG_U_MAX))
			print_64_regular(ns);
		node = node->prev;
	}
}

void				print_64(t_process *process)
{
	t_link				*node;
	t_node_symbol_64	*ns;

	if (process->flag & FLAG_R)
	{
		print_64_reverse(process);
		return ;
	}
	node = process->list_symbol.head;
	if (process->nb_file > 1 && process->is_lib == 0)
	{
		ft_putchar('\n');
		ft_putstr(process->file_name);
		ft_putstr(":\n");
	}
	while (node)
	{
		ns = PTR_NODE(node, t_node_symbol_64, link);
		if (process->flag & FLAG_U_MIN)
			print_64_undefined_only(ns);
		else if (process->flag & FLAG_U_MAX && ns->c != 'U')
			print_64_regular(ns);
		else if (!(process->flag & FLAG_U_MAX))
			print_64_regular(ns);
		node = node->next;
	}
}

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
