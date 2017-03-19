/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:56:45 by nle-bret          #+#    #+#             */
/*   Updated: 2017/03/18 18:56:46 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

int		error(char *str)
{
	ft_putstr_fd(str, 2);
	return (EXIT_FAILURE);
}

void	print_byte(unsigned char byte)
{
	static char	hexa[16] = "0123456789abcdef";

	write(1, &hexa[byte >> 4], 1);
	write(1, &hexa[byte & 15], 1);
}

void	print_addr_64(uint64_t addr)
{
	char	*str;
	int		align;

	str = ulltoa_base(addr, 16);
	align = 16 - ft_strlen(str);
	while (align > 0)
	{
		write(1, "0", 1);
		align--;
	}
	ft_putstr(str);
	free(str);
}

void	print_addr_32(uint32_t addr)
{
	char	*str;
	int		align;

	str = ulltoa_base(addr, 16);
	align = 8 - ft_strlen(str);
	while (align > 0)
	{
		write(1, "0", 1);
		align--;
	}
	ft_putstr(str);
	free(str);
}
