/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 17:02:43 by nle-bret          #+#    #+#             */
/*   Updated: 2017/03/18 17:04:03 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	ft_nm(t_process *process)
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

void	clear_symbol_list(t_list *list)
{
	t_link				*link;
	t_node_symbol_32	*node;

	link = list->head;
	while (link)
	{
		node = PTR_NODE(link, t_node_symbol_32, link);
		link = link->next;
		free(node);
	}
	ft_bzero(list, sizeof(t_list));
}

int		loop_arg(char *file_name, int nb_file, uint8_t flag)
{
	int			fd;
	t_process	process;

	ft_bzero(&process, sizeof(process));
	process.flag = flag;
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
	ft_nm(&process);
	if (munmap(process.ptr_start, process.buff_stat.st_size) < 0)
		return (error("munmap error\n"));
	return (0);
}

int		check_av_flag(char *arg, uint8_t *flag)
{
	int		find;
	int		i;

	i = 0;
	find = 0;
	if (arg[0] != '-')
		return (0);
	while (arg[i])
	{
		if (arg[i] != '-')
		{
			if (arg[i] && arg[i] == 'p' && ++find)
				*flag |= FLAG_P;
			if (arg[i] && arg[i] == 'v' && ++find)
				*flag |= FLAG_V;
			if (arg[i] && arg[i] == 'r' && ++find)
				*flag |= FLAG_R;
			if (arg[i] && arg[i] == 'u' && ++find)
				*flag |= FLAG_U_MIN;
			if (arg[i] && arg[i] == 'U' && ++find)
				*flag |= FLAG_U_MAX;
		}
		i++;
	}
	return (find);
}

int		main(int ac, char **av)
{
	int			i;
	int			nb_file;
	uint8_t		flag;

	nb_file = count_nb_arg_without_flag(ac, av);
	if (ac == 1)
		loop_arg("a.out", 0, 0);
	else if (ac >= 2)
	{
		i = 1;
		while (i < ac)
		{
			if (check_av_flag(av[i], &flag) == 0)
				loop_arg(av[i], nb_file, flag);
			i++;
		}
	}
	return (0);
}
