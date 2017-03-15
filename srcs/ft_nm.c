#include "ft_nm.h"

void		ft_nm(t_process *process)
{
	int 		magic_number;

	magic_number = *(int*)process->ptr;
	if (magic_number == MH_MAGIC_64)
		handle_64(process);
	else if (magic_number == MH_MAGIC)
		handle_32(process);
	else if (magic_number == FAT_CIGAM)
		handle_fat_big_endian(process);
	else if (ft_strncmp(process->ptr, ARMAG, SARMAG) == 0)
		handle_ar(process);
}

int		loop_arg(char *file_name)
{
	int 		fd;
	t_process	process;

	ft_bzero(&process, sizeof(process));
	process.list_symbol.head = NULL;
	process.list_symbol.tail = NULL;
	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (error("open error\n"));
	if (fstat(fd, &process.buff_stat) < 0)
		return (error("fstat error\n"));
	if ((process.ptr = mmap(0, process.buff_stat.st_size,
							PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return (error("mmap error\n"));
	process.ptr_start = process.ptr;
	process.file_name = file_name;
	ft_nm(&process);
	if (munmap(process.ptr_start, process.buff_stat.st_size) < 0)
		return (error("munmap error\n"));
	return (0);
}

int			main(int ac, char **av)
{
	int 	i;

	if (ac == 1)
		loop_arg("a.out");
	else if (ac == 2)
		loop_arg(av[1]);
	else if (ac > 2)
	{
		i = 1;
		while (i < ac)
		{
			loop_arg(av[i]);
			i++;
		}
	}
	return (0);
}