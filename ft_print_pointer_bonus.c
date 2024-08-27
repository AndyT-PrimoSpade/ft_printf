/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtan <andtan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:29:26 by andtan            #+#    #+#             */
/*   Updated: 2024/08/05 06:17:04 by andtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_hex_ptr(unsigned long n)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += print_hex_ptr(n / 16);
	count += write(1, &hex[n % 16], 1);
	return (count);
}

static int	get_ptr_len(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	print_pointer(void *ptr, t_flags *flags)
{
	unsigned long	n;
	int				count;
	int				ptr_len;

	count = 0;
	if (!ptr)
	{
		ptr_len = 5;
		if (!flags->minus && flags->width > ptr_len)
			count += print_width(flags->width - ptr_len, flags->zero,
					flags->minus);
		count += write(1, "(nil)", ptr_len);
		if (flags->minus && flags->width > ptr_len)
			count += print_width(flags->width - ptr_len, 0, flags->minus);
		return (count);
	}
	n = (unsigned long)ptr;
	ptr_len = get_ptr_len(n) + 2;
	if (!flags->minus && flags->width > ptr_len)
		count += print_width(flags->width - ptr_len, flags->zero, flags->minus);
	count += write(1, "0x", 2);
	count += print_hex_ptr(n);
	if (flags->minus && flags->width > ptr_len)
		count += print_width(flags->width - ptr_len, 0, flags->minus);
	return (count);
}
