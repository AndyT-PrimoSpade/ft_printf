/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtan <andtan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:39:18 by andtan            #+#    #+#             */
/*   Updated: 2024/08/18 10:13:59 by andtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	get_hex_len(unsigned long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static int	put_hex(unsigned long n, int uppercase)
{
	char	*hex_lower;
	char	*hex_upper;
	int		count;

	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += put_hex(n / 16, uppercase);
	if (uppercase)
		count += write(1, &hex_upper[n % 16], 1);
	else
		count += write(1, &hex_lower[n % 16], 1);
	return (count);
}

static int	print_hex_prefix(unsigned long n, int uppercase, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->hash && n != 0)
	{
		if (uppercase)
			count += write(1, "0X", 2);
		else
			count += write(1, "0x", 2);
	}
	return (count);
}

static int	print_hex_padding(unsigned long n, int hex_len, t_flags *flags)
{
	int	count;
	int	precision_pad;
	int	width_pad;
	int	hash_value;

	count = 0;
	precision_pad = 0;
	if (flags->precision > hex_len)
		precision_pad = flags->precision - hex_len;
	hash_value = 0;
	if (flags->hash && n != 0)
		hash_value = 2;
	width_pad = 0;
	if (flags->width > (hex_len + precision_pad + hash_value))
		width_pad = flags->width - (hex_len + precision_pad + hash_value);
	if (!flags->minus && width_pad > 0)
	{
		if (flags->zero && flags->precision < 0)
			count += print_width(width_pad, 1, 0);
		else
			count += print_width(width_pad, 0, 0);
	}
	return (count);
}

int	print_hex(unsigned long n, int uppercase, t_flags *flags)
{
	int	count;
	int	hex_len;

	count = 0;
	hex_len = get_hex_len(n);
	if (n == 0 && flags->precision == 0)
		return (print_width(flags->width, 0, flags->minus));
	count += print_hex_padding(n, hex_len, flags);
	count += print_hex_prefix(n, uppercase, flags);
	if (flags->precision > hex_len)
		count += print_width(flags->precision - hex_len, 1, 0);
	if (n != 0 || flags->precision != 0)
		count += put_hex(n, uppercase);
	if (flags->minus)
		count += print_width(flags->width - count, 0, 1);
	return (count);
}
