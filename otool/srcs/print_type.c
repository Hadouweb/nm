/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 17:04:37 by nle-bret          #+#    #+#             */
/*   Updated: 2017/03/18 17:04:53 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static char		get_type_sub_func(t_process *process, uint8_t nsect)
{
	if (nsect == process->text_nsect)
		return ('t');
	else if (nsect == process->data_nsect)
		return ('d');
	else if (nsect == process->bss_nsect)
		return ('b');
	else
		return ('s');
}

char			get_type_32(t_process *process, struct nlist *nl)
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
		c = get_type_sub_func(process, nl->n_sect);
	else if (MASK_T == N_INDR)
		c = 'i';
	if (nl->n_type & N_EXT && c != '?')
		c = ft_toupper(c);
	return (c);
}

char			get_type_64(t_process *process, struct nlist_64 *nl)
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
		c = get_type_sub_func(process, nl->n_sect);
	else if (MASK_T == N_INDR)
		c = 'i';
	if (nl->n_type & N_EXT && c != '?')
		c = ft_toupper(c);
	return (c);
}
