#include "ft_nm.h"

static int	ull_len(unsigned long long value, int base)
{
	int		i;

	i = 0;
	if (value == 0)
		i++;
	while (value)
	{
		value /= base;
		i++;
	}
	return (i);
}

char		*ulltoa_base(unsigned long long value, int base)
{
	char	*str;
	int		size;
	int		sign;

	size = ull_len(value, base);
	if ((str = (char *)ft_memalloc(size + 1)) == NULL)
		return (NULL);
	sign = 1;
	str[size--] = '\0';
	if (value == 0)
		str[0] = '0';
	while (value)
	{
		str[size] = value % base * sign;
		if (str[size] >= 10)
			str[size] += 39;
		str[size] += '0';
		value /= base;
		size--;
	}
	return (str);
}

uint32_t	convert_uint32(uint32_t a)
{
	return ((a << 24) |
		((a << 8) & 0x00ff0000) |
		((a >> 8) & 0x0000ff00) |
		((uint32_t)(a >> 24)));
}