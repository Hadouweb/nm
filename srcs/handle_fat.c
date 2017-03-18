#include "ft_nm.h"

void	handle_fat_big_endian(t_process *process)
{
	int 					i;
	int 					nfat_arch;
	struct fat_header		*header;
	struct fat_arch			*arch;

	//printf("handle_fat_big_endian\n");
	process->is_big_endian = 1;
	header = (struct fat_header *)(process->ptr);
	arch = (void *)(process->ptr) + sizeof(*header);
	nfat_arch = convert_uint32(process, header->nfat_arch);
	i = 0;
	//printf("%d\n", nfat_arch);
	while (i < nfat_arch)
	{
		arch->cputype = convert_uint32(process, arch->cputype);
		arch->offset = convert_uint32(process, arch->offset);
		arch->size = convert_uint32(process, arch->size);
		//debug_fat_arch(arch);
		//printf("__ %u\n", arch->offset);
		ft_putchar('\n');
		ft_putstr(process->file_name);
		if (arch->cputype == CPU_TYPE_X86_64)
		{
			//printf("CPU_TYPE_X86_64\n");
			process->ptr = process->ptr_start + arch->offset;
			//ft_nm(process);
			//return ;
		}
		if (arch->cputype == CPU_TYPE_POWERPC)
		{
			ft_putstr(" (for architecture ppc):\n");
			//printf("CPU_TYPE_POWERPC\n");
			//printf("---------------- CPU_TYPE_POWERPC\n");
			process->ptr = process->ptr_start + arch->offset;
			ft_nm(process);
			//return ;
		}
		if (arch->cputype == CPU_TYPE_X86)
		{
			ft_putstr(" (for architecture i386):\n");
			//printf("CPU_TYPE_X86\n");
			process->ptr = process->ptr_start + arch->offset;
			ft_nm(process);
			//return ;
		}
		arch = (void*)arch + sizeof(*arch);
		i++;
	}
	/*i = 0;
	arch = (void *)(process->ptr_start) + sizeof(*header);
    process->ptr = process->ptr_start;
	while (i < nfat_arch)
	{
		//arch->cputype = convert_uint32(process, arch->cputype);
		//arch->offset = convert_uint32(process, arch->offset);
		printf("__ %u\n", arch->offset);
		if (arch->cputype == CPU_TYPE_X86)
		{
			printf("CPU_TYPE_X86\n");
			process->ptr = process->ptr_start + arch->offset;
			//ft_nm(process);
			//return ;
		}
		arch = (void*)arch + sizeof(*arch);
		i++;
	}*/
    /*i = 0;
    arch = (void *)(process->ptr_start) + sizeof(*header);
    process->ptr = process->ptr_start;
    while (i < nfat_arch)
    {
        if (convert_uint32(arch->cputype) == CPU_TYPE_POWERPC)
        {
            printf("---------------- CPU_TYPE_POWERPC\n");
            process->ptr += convert_uint32(arch->offset);
            ft_nm(process);
            //return ;
        }
        arch = (void*)arch + sizeof(*arch);
        i++;
    }*/
}