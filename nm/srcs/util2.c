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

int		count_nb_arg_without_flag(int ac, char **av)
{
	int			i;
	int			nb_file;
	uint8_t		flag;

	i = 1;
	nb_file = 0;
	while (i < ac)
	{
		if (check_av_flag(av[i], &flag) == 0)
			nb_file++;
		i++;
	}
	return (nb_file);
}

void	clear_process(t_process *process)
{
	clear_symbol_list(&process->list_symbol);
	free(process->section_64);
	free(process->section_32);
	process->text_nsect = 0;
	process->data_nsect = 0;
	process->bss_nsect = 0;
	process->nsects = 0;
	process->load_command = NULL;
	process->sym = NULL;
}
