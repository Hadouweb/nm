#include "ft_nm.h"

void	handle_fat_big_endian(t_process *process)
{
	int 					i;
	int 					nfat_arch;
	struct fat_header		*header;
	struct fat_arch			*arch;

	printf("handle_fat_big_endian\n");
	header = (struct fat_header *)(process->ptr);
	arch = (void *)(process->ptr) + sizeof(*header);
	nfat_arch = convert_uint32(header->nfat_arch);
	i = 0;
	while (i < nfat_arch)
	{
		if (convert_uint32(arch->cputype) == CPU_TYPE_X86_64)
		{
			process->ptr += convert_uint32(arch->offset);
			ft_nm(process);
			//return ;
		}
		arch = (void*)arch + sizeof(*arch);
		i++;
	}
	i = 0;
	arch = (void *)(process->ptr_start) + sizeof(*header);
    process->ptr = process->ptr_start;
	while (i < nfat_arch)
	{
		if (convert_uint32(arch->cputype) == CPU_TYPE_X86)
		{
			process->ptr += convert_uint32(arch->offset);
			ft_nm(process);
			//return ;
		}
		arch = (void*)arch + sizeof(*arch);
		i++;
	}
    i = 0;
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
    }
}