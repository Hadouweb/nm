#include "ft_nm.h"

char	get_type_32(t_process *process, struct nlist *nl)
{
	char	c;

	c = '?';
	if (MASK_T == N_UNDF)
	{
		c = 'u';
		if (nl->n_value != 0)
			c = 'c';
	}
	else if (MASK_T == N_PBUD)
			c = 'u';
	else if (MASK_T == N_ABS)
		c = 'a';
	else if (MASK_T == N_SECT)
	{
		if (nl->n_sect == process->text_nsect)
			c = 't';
		else if (nl->n_sect == process->data_nsect)
			c = 'd';
		else if (nl->n_sect == process->bss_nsect)
			c = 'b';
		else
			c = 's';
	}
	else if (MASK_T == N_INDR)
		c = 'i';
	if (nl->n_type & N_EXT && c != '?')
		c = ft_toupper(c);
	return c;
}

char	get_type_64(t_process *process, struct nlist_64 *nl)
{
	char	c;

	c = '?';
	if (MASK_T == N_UNDF)
	{
		c = 'u';
		if (nl->n_value != 0)
			c = 'c';
	}
	else if (MASK_T == N_PBUD)
		c = 'u';
	else if (MASK_T == N_ABS)
		c = 'a';
	else if (MASK_T == N_SECT)
	{
		if (nl->n_sect == process->text_nsect)
			c = 't';
		else if (nl->n_sect == process->data_nsect)
			c = 'd';
		else if (nl->n_sect == process->bss_nsect)
			c = 'b';
		else
			c = 's';
	}
	else if (MASK_T == N_INDR)
		c = 'i';
	if (nl->n_type & N_EXT && c != '?')
		c = ft_toupper(c);
	return c;
}