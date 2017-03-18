/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 17:04:17 by nle-bret          #+#    #+#             */
/*   Updated: 2017/03/18 17:04:18 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static int	get_ar_hdr_size(char *ar_name)
{
	char		*str_size;

	str_size = ft_strstr(ar_name, "/");
	return ((str_size != NULL) ? ft_atoi(str_size + 1) : -1);
}

void		sub_call_nm_object(t_process *process)
{
	struct ar_hdr		*header;
	uint32_t			magic_nb;
	void				*tmp;

	header = (void*)process->ptr;
	tmp = process->ptr;
	ft_putchar('\n');
	ft_putstr(process->file_name);
	ft_putchar('(');
	ft_putstr(header->ar_name + sizeof(*header));
	ft_putstr("):\n");
	process->ptr += sizeof(*header) + get_ar_hdr_size(header->ar_name);
	magic_nb = *(uint32_t*)process->ptr;
	if (magic_nb == MH_MAGIC)
		handle_32(process, 0);
	else if (magic_nb == MH_MAGIC_64)
		handle_64(process);
	process->ptr = tmp;
}

void		handle_ar(t_process *process)
{
	struct ar_hdr		*header;
	char				*end_file;

	process->is_lib = 1;
	process->ptr += SARMAG;
	header = (struct ar_hdr*)process->ptr;
	process->ptr += ft_atoi(header->ar_size) + sizeof(*header);
	header = (struct ar_hdr*)process->ptr;
	end_file = process->ptr_start + process->buff_stat.st_size;
	while (process->ptr + ft_atoi(header->ar_size) + sizeof(*header) <=
		end_file)
	{
		sub_call_nm_object(process);
		process->ptr += ft_atoi(header->ar_size) + sizeof(*header);
		header = (struct ar_hdr*)process->ptr;
	}
}
