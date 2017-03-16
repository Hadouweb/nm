#include "ft_nm.h"
#include <inttypes.h>
/*
 * struct mach_header_64 {
 *     uint32_t			magic;			// mach magic number identifier
 *     cpu_type_t		cputype;		// cpu specifier
 *     cpu_subtype_t	cpusubtype;		// machine specifier
 *     uint32_t			filetype;		// type of file
 *     uint32_t			ncmds;			// number of load commands
 *     uint32_t			sizeofcmds;		// the size of all the load commands
 *     uint32_t			flags;			// flags
 *     uint32_t			reserved;		// reserved
 * };
 */
void	debug_header_64(struct mach_header_64 *header)
{
	printf("***** HEADER 64 ******\n");
	printf("magic: %u\n", header->magic);
	printf("cpu_type_t: %u\n", header->cputype);
	printf("cpu_subtype_t: %u\n", header->cpusubtype);
	printf("filetype: %u\n", header->filetype);
	printf("ncmds: %u\n", header->ncmds);
	printf("sizeofcmds: %u\n", header->sizeofcmds);
	printf("flags: %u\n", header->flags);
	printf("reserved: %u\n", header->reserved);
}

/*
 * struct mach_header {
 *     uint32_t			magic;			// mach magic number identifier
 *     cpu_type_t		cputype;		// cpu specifier
 *     cpu_subtype_t	cpusubtype;		// machine specifier
 *     uint32_t			filetype;		// type of file
 *     uint32_t			ncmds;			// number of load commands
 *     uint32_t			sizeofcmds;		// the size of all the load commands
 *     uint32_t			flags;			// flags
 * };
 */
void	debug_header_32(struct mach_header *header)
{
	printf("***** HEADER 32 ******\n");
	printf("magic: %u\n", header->magic);
	printf("cpu_type_t: %u\n", header->cputype);
	printf("cpu_subtype_t: %u\n", header->cpusubtype);
	printf("filetype: %u\n", header->filetype);
	printf("ncmds: %u\n", header->ncmds);
	printf("sizeofcmds: %u\n", header->sizeofcmds);
	printf("flags: %u\n", header->flags);
}

/*
 * struct load_command {
 * 		uint32_t cmd;		// type of load command
 * 		uint32_t cmdsize;	// total size of command in bytes
 * };
 */
void	debug_load_command(struct load_command *lc)
{
	printf("***** LOAD_COMMAND ******\n");
	printf("cmd: %u (%x)\n", lc->cmd, lc->cmd);
	printf("cmdsize: %u\n", lc->cmdsize);
}

/*
 * struct symtab_command {
 *     uint32_t	cmd;		// LC_SYMTAB
 *     uint32_t	cmdsize;	// sizeof(struct symtab_command)
 *     uint32_t	symoff;		// symbol table offset
 *     uint32_t	nsyms;		// number of symbol table entries
 *     uint32_t	stroff;		// string table offset
 *     uint32_t	strsize;	// string table size in bytes
 * };
 */
void	debug_symtab_command(struct symtab_command *sym)
{
	printf("***** SYMTAB_COMMAND ******\n");
	printf("cmd: %u\n", sym->cmd);
	printf("cmdsize: %u\n", sym->cmdsize);
	printf("symoff: %u\n", sym->symoff);
	printf("nsyms: %u\n", sym->nsyms);
	printf("stroff: %u\n", sym->stroff);
	printf("strsize: %u\n", sym->strsize);
}

/*
 * struct nlist_64 {
 * 	   union {
 * 	   		uint32_t n_strx;	// index into the string table
 * 	   } n_un;
 * 	   uint8_t n_type;		// type flag, see below
 * 	   uint8_t n_sect;		// section number or NO_SECT
 * 	   int16_t n_desc;		// see <mach-o/stab.h>
 * 	   uint64_t n_value;	// value of this symbol (or stab offset)
 * };
 */
void	debug_nlist_64(struct nlist_64 *nlist)
{
	printf("***** NLIST_64 ******\n");
	printf("n_strx: %u\n", nlist->n_un.n_strx);
	printf("n_type: %u (%x)\n", nlist->n_type, nlist->n_type);
	printf("n_sect: %u\n", nlist->n_sect);
	printf("n_desc: %u\n", nlist->n_desc);
	printf("n_value: %llu\n", nlist->n_value);
}

/*
 * struct nlist_64 {
 * 	   union {
 * 	   		uint32_t n_strx;	// index into the string table
 * 	   } n_un;
 * 	   uint8_t n_type;		// type flag, see below
 * 	   uint8_t n_sect;		// section number or NO_SECT
 * 	   int16_t n_desc;		// see <mach-o/stab.h>
 * 	   uint32_t n_value;	// value of this symbol (or stab offset)
 * };
 */
void	debug_nlist_32(struct nlist *nlist)
{
	printf("***** NLIST_32 ******\n");
	printf("n_strx: %u\n", nlist->n_un.n_strx);
	printf("n_type: %u (%x)\n", nlist->n_type, nlist->n_type);
	printf("n_sect: %u\n", nlist->n_sect);
	printf("n_desc: %u\n", nlist->n_desc);
	printf("n_value: %u\n", nlist->n_value);
}

/*
 *  struct segment_command { 		// for 32-bit architectures
 *  	uint32_t	cmd;			// LC_SEGMENT
 *  	uint32_t	cmdsize;		// includes sizeof section structs
 *  	char		segname[16];	// segment name
 *  	uint32_t	vmaddr;			// memory address of this segment
 *  	uint32_t	vmsize;			// memory size of this segment
 *  	uint32_t	fileoff;		// file offset of this segment
 *  	uint32_t	filesize;		// amount to map from the file
 *  	vm_prot_t	maxprot;		// maximum VM protection
 *  	vm_prot_t	initprot;		// initial VM protection
 *  	uint32_t	nsects;			// number of sections in segment
 *  	uint32_t	flags;			// flags
 *  };
 */
void	debug_segment_cmd_32(struct segment_command *segment)
{
	printf("***** SEGMENT_COMMAND_32 ******\n");
	printf("cmd: %u\n", segment->cmd);
	printf("cmdsize: %u\n", segment->cmdsize);
	printf("segname[16]: %s\n", segment->segname);
	printf("vmaddr: %u\n", segment->vmaddr);
	printf("vmsize: %u\n", segment->vmsize);
	printf("fileoff: %u\n", segment->fileoff);
	printf("filesize: %u\n", segment->filesize);
	printf("maxprot: %d\n", segment->maxprot);
	printf("initprot: %d\n", segment->initprot);
	printf("nsects: %u\n", segment->nsects);
	printf("flags: %u\n", segment->flags);
}

/*
 *  struct segment_command_64 { 	// for 64-bit architectures
 *  	uint32_t	cmd;			// LC_SEGMENT
 *  	uint32_t	cmdsize;		// includes sizeof section structs
 *  	char		segname[16];	// segment name
 *  	uint64_t	vmaddr;			// memory address of this segment
 *  	uint64_t	vmsize;			// memory size of this segment
 *  	uint64_t	fileoff;		// file offset of this segment
 *  	uint64_t	filesize;		// amount to map from the file
 *  	vm_prot_t	maxprot;		// maximum VM protection
 *  	vm_prot_t	initprot;		// initial VM protection
 *  	uint32_t	nsects;			// number of sections in segment
 *  	uint32_t	flags;			// flags
 *  };
 */
void	debug_segment_cmd_64(struct segment_command_64 *segment)
{
	printf("***** SEGMENT_COMMAND_64 ******\n");
	printf("cmd: %u\n", segment->cmd);
	printf("cmdsize: %u\n", segment->cmdsize);
	printf("segname[16]: %s\n", segment->segname);
	printf("vmaddr: %llu\n", segment->vmaddr);
	printf("vmsize: %llu\n", segment->vmsize);
	printf("fileoff: %llu\n", segment->fileoff);
	printf("filesize: %llu\n", segment->filesize);
	printf("maxprot: %d\n", segment->maxprot);
	printf("initprot: %d\n", segment->initprot);
	printf("nsects: %u\n", segment->nsects);
	printf("flags: %u\n", segment->flags);
}

/*
 *  struct section { 				// for 32-bit architectures
 *  	char		sectname[16];	// name of this section
 *  	char		segname[16];	// segment this section goes in
 *  	uint32_t	addr;			// memory address of this section
 *  	uint32_t	size;			// size in bytes of this section
 *  	uint32_t	offset;			// file offset of this section
 *  	uint32_t	align;			// section alignment (power of 2)
 *  	uint32_t	reloff;			// file offset of relocation entries
 *  	uint32_t	nreloc;			// number of relocation entries
 *  	uint32_t	flags;			// flags (section type and attributes
 *  	uint32_t	reserved1;		// reserved (for offset or index)
 *  	uint32_t	reserved2;		// reserved (for count or sizeof)
 *  };
 */
void	debug_section_32(struct section *section)
{
	printf("***** SECTION_32 ******\n");
	printf("sectname: %s\n", section->sectname);
	printf("segname: %s\n", section->segname);
	printf("addr: %u\n", section->addr);
	printf("size: %u\n", section->size);
	printf("offset: %u\n", section->offset);
	printf("align: %u\n", section->align);
	printf("reloff: %u\n", section->reloff);
	printf("nreloc: %u\n", section->nreloc);
	printf("flags: %u\n", section->flags);
	printf("reserved1: %u\n", section->reserved1);
	printf("reserved2: %u\n", section->reserved2);
}

/*
 *  struct section_64 { 			// for 64-bit architectures
 *  	char		sectname[16];	// name of this section
 *  	char		segname[16];	// segment this section goes in
 *  	uint64_t	addr;			// memory address of this section
 *  	uint64_t	size;			// size in bytes of this section
 *  	uint32_t	offset;			// file offset of this section
 *  	uint32_t	align;			// section alignment (power of 2)
 *  	uint32_t	reloff;			// file offset of relocation entries
 *  	uint32_t	nreloc;			// number of relocation entries
 *  	uint32_t	flags;			// flags (section type and attributes
 *  	uint32_t	reserved1;		// reserved (for offset or index)
 *  	uint32_t	reserved2;		// reserved (for count or sizeof)
 *  };
 */
void	debug_section_64(struct section_64 *section)
{
	printf("***** SECTION_64 ******\n");
	printf("sectname: %s\n", section->sectname);
	printf("segname: %s\n", section->segname);
	printf("addr: %llu\n", section->addr);
	printf("size: %llu\n", section->size);
	printf("offset: %u\n", section->offset);
	printf("align: %u\n", section->align);
	printf("reloff: %u\n", section->reloff);
	printf("nreloc: %u\n", section->nreloc);
	printf("flags: %u\n", section->flags);
	printf("reserved1: %u\n", section->reserved1);
	printf("reserved2: %u\n", section->reserved2);
}

/*
 *  struct ar_hdr {
 *  	char ar_name[16];		// name
 *  	char ar_date[12];		// modification time
 *  	char ar_uid[6];			// user id
 *  	char ar_gid[6];			// group id
 *  	char ar_mode[8];		// octal file permissions
 *  	char ar_size[10];		// size in bytes
 *  #define	ARFMAG	"`\n"
 *  	char ar_fmag[2];		// consistency check
 *  };
 */
void	debug_ar_header(struct ar_hdr *header)
{
	printf("***** AR_HEADER ******\n");
	printf("ar_name: [%.16s]\n", header->ar_name);
	printf("ar_date: [%.12s]\n", header->ar_date);
	printf("ar_uid: [%.6s]\n", header->ar_uid);
	printf("ar_gid: [%.6s]\n", header->ar_gid);
	printf("ar_mode: [%.8s]\n", header->ar_mode);
	printf("ar_size: [%.10s]\n", header->ar_size);
	printf("ar_fmag: [%.2s]\n", header->ar_fmag);
}