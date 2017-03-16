#include "ft_nm.h"

void				print_sym_value_32(uint32_t sym_value, char type)
{
	char	*str;
	int 	align;
	char 	t;

	t = ft_toupper(type);
	if (t == 'T' || t == 'B' || t == 'D' || t == 'S' ||
		t == 'I' || t == 'A' || t == 'C')
	{
		str = ulltoa_base(sym_value, 16);
		align = 8 - ft_strlen(str);
		while (align--)
			write(1, "0", 1);
		ft_putstr(str);
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
	return ns;
}

int 				compare_32(t_node_symbol_32 *ns1, t_node_symbol_32 *ns2)
{
	int		cmp;

	cmp = ft_strcmp(ns1->output, ns2->output);
	if (cmp == 0)
		cmp = ns1->nl->n_value - ns2->nl->n_value;
	return cmp;
}

void				insertion_sort_symbol_32(t_process *process,
	t_node_symbol_32 *ns)
{
	t_link				*node;
	t_node_symbol_32	*ns2;

	node = process->list_symbol.head;
	if (node != NULL)
	{
		while (node)
		{
			ns2 = PTR_NODE(node, t_node_symbol_32, link);
			if (compare_32(ns, ns2) < 0)
			{
				ft_list_push_before_node(&process->list_symbol,
				&ns2->link,&ns->link);
				return ;
			}
			node = node->next;
		}
	}
	ft_list_push_back(&process->list_symbol, &ns->link);
}

void				sort_symbol_32(t_process *process)
{
	uint32_t 			i;
	char 				*string_table;
	struct nlist		*array;
	char 				*output;
	t_node_symbol_32	*ns;

	array = (void*)process->ptr + process->sym->symoff;
	string_table = (void*)process->ptr + process->sym->stroff;
	i = 0;
	while (i < process->sym->nsyms)
	{
		if ((array[i].n_type & N_TYPE) == N_SECT && array[i].n_sect >= 1 &&
			array[i].n_un.n_strx > 1)
		{
			output = (string_table + array[i].n_un.n_strx);
			ns = make_node_symbol_32(process, output, &array[i]);
			insertion_sort_symbol_32(process, ns);
		}
		else if ((array[i].n_type & N_STAB) == N_UNDF)
		{
			output = (string_table + array[i].n_un.n_strx);
			ns = make_node_symbol_32(process, output, &array[i]);
			insertion_sort_symbol_32(process, ns);
		}
		i++;
	}
	print_32(process);
}
