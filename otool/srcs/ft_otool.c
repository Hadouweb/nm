/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:31:46 by nle-bret          #+#    #+#             */
/*   Updated: 2017/03/19 18:31:49 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

void	ft_otool(t_process *process)
{
	uint32_t	magic_number;

	magic_number = *(uint32_t *)process->ptr;
	if (magic_number == MH_MAGIC_64)
		handle_64(process);
	else if (magic_number == MH_MAGIC)
		handle_32(process, 0);
	else if (magic_number == MH_CIGAM)
		handle_32(process, 1);
	else if (magic_number == FAT_CIGAM)
		handle_fat_big_endian(process);
	else if (ft_strncmp(process->ptr, ARMAG, SARMAG) == 0)
		handle_ar(process);
}

void	clear_process(t_process *process)
{
	process->nsects = 0;
	process->load_command = NULL;
}

int		loop_arg(char *file_name, int nb_file)
{
	int			fd;
	t_process	process;

	ft_bzero(&process, sizeof(process));
	process.nb_file = nb_file;
	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (error("open error\n"));
	if (fstat(fd, &process.buff_stat) < 0)
		return (error("fstat error\n"));
	if ((process.ptr = mmap(0, process.buff_stat.st_size,
	PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return (error("mmap error\n"));
	process.ptr_start = process.ptr;
	process.file_name = file_name;
	ft_otool(&process);
	if (munmap(process.ptr_start, process.buff_stat.st_size) < 0)
		return (error("munmap error\n"));
	return (0);
}

int		main(int ac, char **av)
{
	int		i;

	if (ac == 2)
		loop_arg(av[1], 1);
	else if (ac > 2)
	{
		i = 1;
		while (i < ac)
		{
			loop_arg(av[i], ac - 1);
			i++;
		}
	}
	return (0);
}
