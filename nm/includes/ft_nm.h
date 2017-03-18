/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:22:56 by nle-bret          #+#    #+#             */
/*   Updated: 2017/03/18 19:22:57 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include <mach-o/nlist.h>
# include <mach-o/loader.h>
# include <mach-o/stab.h>
# include <mach-o/fat.h>
# include <mach-o/ranlib.h>
# include <mach/machine.h>
# include <ar.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <stdlib.h>
# include "libft.h"

# include <stdio.h>

# define MASK_T (nl->n_type & N_TYPE)

typedef struct			s_node_symbol_32
{
	t_link						link;
	char						*output;
	char						c;
	struct nlist				*nl;
}						t_node_symbol_32;

typedef struct			s_node_symbol_64
{
	t_link						link;
	char						*output;
	char						c;
	struct nlist_64				*nl;
}						t_node_symbol_64;

typedef struct			s_arch_node
{
	struct fat_arch				*arch;
	void						*ptr_arch;
}						t_arch_node;

typedef struct			s_process
{
	char						*file_name;
	char						*ptr;
	char						*ptr_start;
	uint32_t					nsects;
	struct symtab_command		*sym;
	struct load_command			*load_command;
	struct mach_header			*header_32;
	struct section				**section_32;
	struct mach_header_64		*header_64;
	struct section_64			**section_64;
	unsigned char				text_nsect;
	unsigned char				data_nsect;
	unsigned char				bss_nsect;
	t_list						list_symbol;
	struct stat					buff_stat;
	int							nb_file;
	int							is_big_endian;
	unsigned char				is_lib;
	t_arch_node					arch[3];
}						t_process;

int						error(char *str);

void					ft_nm(t_process *process);

void					handle_32(t_process *process, char mode);
void					add_section_32(t_process *process);
char					get_type_32(t_process *process, struct nlist *nl);
int						compare_32(t_node_symbol_32 *ns1,
							t_node_symbol_32 *ns2);
t_node_symbol_32		*make_node_symbol_32(t_process *process,
							char *output, struct nlist *nl);
void					insertion_sort_symbol_32(t_process *process,
							t_node_symbol_32 *ns);
void					sort_symbol_32(t_process *process);
void					print_32(t_process *process);
void					print_sym_value_32(uint32_t sym_value, char type);

void					handle_64(t_process *process);
void					add_section_64(t_process *process);
char					get_type_64(t_process *process, struct nlist_64 *nl);
int						compare_64(t_node_symbol_64 *ns1,
							t_node_symbol_64 *ns2);
t_node_symbol_64		*make_node_symbol_64(t_process *process,
							char *output, struct nlist_64 *nl);
void					insertion_sort_symbol_64(t_process *process,
							t_node_symbol_64 *ns);
void					sort_symbol_64(t_process *process);
void					print_64(t_process *process);
void					print_sym_value_64(uint64_t sym_value, char type);

void					handle_fat_big_endian(t_process *process);

void					handle_ar(t_process *process);

char					*ulltoa_base(unsigned long long value, int base);
uint32_t				convert_uint32(t_process *process, uint32_t a);
struct load_command		*convert_load_cmd(t_process *process,
							struct load_command *lc);
struct symtab_command	*convert_symtab(t_process *process,
							struct symtab_command *sym);
void					add_memory_type(t_process *process, char *name, int k);

void					clear_process(t_process *process);

void					debug_header_64(struct mach_header_64 *header);
void					debug_header_32(struct mach_header *header);
void					debug_load_command(struct load_command *lc);
void					debug_symtab_command(struct symtab_command *sym);
void					debug_nlist_64(struct nlist_64 *nlist);
void					debug_nlist_32(struct nlist *nlist);
void					debug_segment_cmd_32(struct segment_command *segment);
void					debug_segment_cmd_64(
							struct segment_command_64 *segment);
void					debug_section_32(struct section *section);
void					debug_section_64(struct section_64 *section);
void					debug_ar_header(struct ar_hdr *header);
void					debug_fat_arch(struct fat_arch *fa);

#endif
