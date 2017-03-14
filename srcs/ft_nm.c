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

int			main(int ac, char **av)
{
	int			fd;
	t_process	process;

	ft_bzero(&process, sizeof(process));
	process.list_symbol.head = NULL;
	process.list_symbol.tail = NULL;
	if (ac != 2)
		return (error("Please give me an arg\n"));
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (error("open error\n"));
	if (fstat(fd, &process.buff_stat) < 0)
		return (error("fstat error\n"));
	if ((process.ptr = mmap(0, process.buff_stat.st_size,
	PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return (error("mmap error\n"));
	process.ptr_start = process.ptr;
	process.file_name = av[1];
	ft_nm(&process);
	if (munmap(process.ptr_start, process.buff_stat.st_size) < 0)
		return (error("munmap error\n"));
	return (0);
}