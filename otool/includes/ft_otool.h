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

#ifndef FT_OTOOL_H
# define FT_OTOOL_H

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
	struct load_command			*load_command;
	struct mach_header			*header_32;
	struct mach_header_64		*header_64;
	struct stat					buff_stat;
	int							nb_file;
	int							is_big_endian;
	unsigned char				is_lib;
	t_arch_node					arch[3];
}						t_process;

int						error(char *str);

void					ft_otool(t_process *process);

void					handle_32(t_process *process, char mode);
void					handle_64(t_process *process);

void					handle_fat_big_endian(t_process *process);

void					handle_ar(t_process *process);

char					*ulltoa_base(unsigned long long value, int base);
uint32_t				convert_uint32(t_process *process, uint32_t a);
struct load_command		*convert_load_cmd(t_process *process,
							struct load_command *lc);
void					print_byte(unsigned char byte);
void					print_addr_64(uint64_t addr);
void					print_addr_32(uint32_t addr);
void					clear_process(t_process *process);

#endif
