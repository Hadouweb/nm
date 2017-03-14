#include "ft_nm.h"

static int				get_arheader_size(char *ar_name)
{
	char		*str_size;

	str_size = ft_strstr(ar_name, "/");
	return ((str_size != NULL) ? ft_atoi(str_size + 1) : -1);
}

void	test(t_process *process)
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
	process->ptr += sizeof(*header) + get_arheader_size(header->ar_name);
	magic_nb = *(uint32_t*)process->ptr;
	if (magic_nb == MH_MAGIC)
		handle_32(process);
	else if (magic_nb == MH_MAGIC_64)
		handle_64(process);
	process->ptr = tmp;
}

void	handle_ar(t_process *process)
{
	struct ar_hdr		*header;
	char				*end_file;

	process->ptr += SARMAG;
	header = (struct ar_hdr*)process->ptr;
	process->ptr += ft_atoi(header->ar_size) + sizeof(*header);
	header = (struct ar_hdr*)process->ptr;
	//debug_ar_header(header);
	end_file = process->ptr_start + process->buff_stat.st_size;
	while (process->ptr + ft_atoi(header->ar_size) + sizeof(*header) <= end_file)
	{
		//debug_ar_header(header);
		//ft_putstr(header->ar_name + sizeof(*header));
		//ft_putchar('\n');
		test(process);
		process->ptr += ft_atoi(header->ar_size) + sizeof(*header);
		header = (struct ar_hdr*)process->ptr;
	}
	//printf("handle_ar\n");
}