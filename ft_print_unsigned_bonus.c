/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtan <andtan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:39:06 by andtan            #+#    #+#             */
/*   Updated: 2024/08/18 10:18:36 by andtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	get_num_len(unsigned long long n)
{
	int	len;

	if (n == 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_putunbr(unsigned long long n)
{
	char	c;

	if (n >= 10)
		ft_putunbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

static int	handle_zero_precision(t_flags *flags)
{
	return (print_width(flags->width, 0, flags->minus));
}

static int	print_padded_number(unsigned long long num, int num_len,
		int zero_pad, t_flags *flags)
{
	int	count;

	count = 0;
	if (zero_pad > 0)
		count += print_width(zero_pad, 1, 0);
	if (num != 0 || flags->precision != 0)
	{
		ft_putunbr(num);
		count += num_len;
	}
	return (count);
}

int	print_unsigned(unsigned int n, t_flags *flags)
{
	int					count;
	int					num_len;
	int					zero_pad;
	int					width_pad;
	unsigned long long	num;

	num = (unsigned long long)n;
	if (num == 0 && flags->precision == 0)
		return (handle_zero_precision(flags));
	num_len = get_num_len(num);
	zero_pad = 0;
	if (flags->precision > num_len)
		zero_pad = flags->precision - num_len;
	width_pad = 0;
	if (flags->width > num_len + zero_pad)
		width_pad = flags->width - (num_len + zero_pad);
	count = 0;
	if (!flags->minus && width_pad > 0)
		count += print_width(width_pad, flags->zero && flags->precision < 0, 0);
	count += print_padded_number(num, num_len, zero_pad, flags);
	if (flags->minus && width_pad > 0)
		count += print_width(width_pad, 0, 1);
	return (count);
}
