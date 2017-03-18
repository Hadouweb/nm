/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:56:45 by nle-bret          #+#    #+#             */
/*   Updated: 2017/03/18 18:56:46 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int		error(char *str)
{
	ft_putstr_fd(str, 2);
	return (EXIT_FAILURE);
}

void	add_memory_type(t_process *process, char *name, int k)
{
	if (ft_strcmp(name, SECT_TEXT) == 0)
		process->text_nsect = k + 1;
	else if (ft_strcmp(name, SECT_DATA) == 0)
		process->data_nsect = k + 1;
	else if (ft_strcmp(name, SECT_BSS) == 0)
		process->bss_nsect = k + 1;
}
