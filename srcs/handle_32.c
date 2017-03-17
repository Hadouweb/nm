#include "ft_nm.h"

static void		add_memory_type_32(t_process *process, struct section *section,
	int k)
{
	if(ft_strcmp(section->sectname, SECT_TEXT) == 0)
		process->text_nsect = k + 1;
	else if(ft_strcmp(section->sectname, SECT_DATA) == 0)
		process->data_nsect = k + 1;
	else if(ft_strcmp(section->sectname, SECT_BSS) == 0)
		process->bss_nsect = k + 1;
}

static void		add_section_32_subfunc(t_process *process,
	int *k, struct load_command *lc)
{
	uint32_t 					j;
	struct segment_command 		*sg;
	struct section 				*s;

	j = 0;
	sg = (struct segment_command *)lc;
	s = (struct section *)((char *)sg + sizeof(struct segment_command));
	while (j < sg->nsects)
	{
		process->section_32[*k] = s + j;
		add_memory_type_32(process, process->section_32[*k], *k);
		(*k)++;
		j++;
	}
}

void			add_section_32(t_process *process)
{
	uint32_t					i;
	int 						k;
	struct load_command			*lc;

	i = 0;
	k = 0;
	process->section_32 = (struct section **)
			malloc(sizeof(struct section *) * process->nsects);
	lc = process->load_command;
	while (i < process->header_32->ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
			add_section_32_subfunc(process, &k, lc);
		i++;
		lc = (void*)lc + lc->cmdsize;
	}
}

void			handle_32(t_process *process)
{
	int 					ncmds;
	int 					i;
	struct load_command		*lc;

	process->header_32 = (struct mach_header*)process->ptr;
    if (process->is_big_endian)
        ncmds = convert_uint32(process->header_32->ncmds);
    else
	    ncmds = process->header_32->ncmds;
    debug_header_32(process->header_32);
	process->load_command = (void*)process->ptr + sizeof(*process->header_32);
	lc = process->load_command;
	i = 0;
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
			process->sym = (struct symtab_command*)lc;
		else if (lc->cmd == LC_SEGMENT)
		{
			process->segment_32 = (struct segment_command *)lc;
			process->nsects += process->segment_32->nsects;
		}
		i++;
        if (process->is_big_endian)
            lc = (void*)lc + convert_uint32(lc->cmdsize);
        else
            lc = (void*)lc + lc->cmdsize;
	}
	if (process->nsects > 0)
		add_section_32(process);
	if (process->sym)
		sort_symbol_32(process);
	clear_process(process);
}