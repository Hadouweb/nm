#include "ft_nm.h"

void	add_all_arch(t_process *process)
{
	int 					i;
	int 					nfat_arch;
	struct fat_header		*header;
	struct fat_arch			*arch;

	process->is_big_endian = 1;
	header = (struct fat_header *)(process->ptr);
	arch = (void *)(process->ptr) + sizeof(*header);
	nfat_arch = convert_uint32(process, header->nfat_arch);
	i = 0;
	while (i < nfat_arch)
	{
		arch->cputype = convert_uint32(process, arch->cputype);
		arch->offset = convert_uint32(process, arch->offset);
		if (arch->cputype == CPU_TYPE_X86_64 && process->arch[0].arch == NULL)
		{
			process->arch[0].arch = arch;
			process->arch[0].ptr_arch = process->ptr_start + arch->offset;
		}
		if (arch->cputype == CPU_TYPE_X86)
		{
			process->arch[1].arch = arch;
			process->arch[1].ptr_arch = process->ptr_start + arch->offset;
		}
		if (arch->cputype == CPU_TYPE_POWERPC)
		{
			process->arch[2].arch = arch;
			process->arch[2].ptr_arch = process->ptr_start + arch->offset;
		}
		arch = (void*)arch + sizeof(*arch);
		i++;
	}
}

void    print_arch(t_process *process, char *arch)
{
    if (process->arch[2].arch != NULL)
    {
        ft_putchar('\n');
        ft_putstr(process->file_name);
        ft_putstr(arch);
    }
}

void	handle_fat_big_endian(t_process *process)
{
    //printf("handle_fat_big_endian\n");
	add_all_arch(process);
    if (process->arch[2].arch != NULL)
    {
        print_arch(process, " (for architecture ppc):\n");
        //printf("CPU_TYPE_POWERPC\n");
        process->ptr = process->arch[2].ptr_arch;
        ft_nm(process);
    }
	if (process->arch[0].arch != NULL)
	{
		//printf("CPU_TYPE_X86_64\n");
		process->ptr = process->arch[0].ptr_arch;
		ft_nm(process);
	}
	if (process->arch[1].arch != NULL && process->arch[0].arch == NULL )
	{
        print_arch(process, " (for architecture i386):\n");
		//printf("CPU_TYPE_X86\n");
		process->ptr = process->arch[1].ptr_arch;
		ft_nm(process);
	}
}