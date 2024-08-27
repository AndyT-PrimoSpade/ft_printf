/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtan <andtan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:34:42 by andtan            #+#    #+#             */
/*   Updated: 2024/08/18 09:37:12 by andtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	get_num_len(long long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	print_sign(long long n, t_flags *flags)
{
	if (n < 0)
		return (write(1, "-", 1));
	else if (flags->plus)
		return (write(1, "+", 1));
	else if (flags->space)
		return (write(1, " ", 1));
	return (0);
}

static int	get_padding_lengths(long long num, int num_len, t_flags *flags,
		int *zero_pad)
{
	int	sign;
	int	total_len;
	int	width_pad;

	if (num < 0 || flags->plus || flags->space)
		sign = 1;
	else
		sign = 0;
	if (flags->precision > num_len)
		*zero_pad = flags->precision - num_len;
	else
		*zero_pad = 0;
	total_len = num_len + sign + *zero_pad;
	if (flags->width > total_len)
		width_pad = flags->width - total_len;
	else
		width_pad = 0;
	return (width_pad);
}

static int	print_integer_padding(long long num, int num_len, t_flags *flags)
{
	int	count;
	int	zero_pad;
	int	width_pad;

	count = 0;
	width_pad = get_padding_lengths(num, num_len, flags, &zero_pad);
	if (!flags->minus && width_pad > 0 && (!flags->zero
			|| flags->precision >= 0))
		count += print_width(width_pad, 0, 0);
	count += print_sign(num, flags);
	if (flags->zero && flags->precision < 0 && !flags->minus)
		count += print_width(width_pad, 1, 0);
	if (zero_pad > 0)
		count += print_width(zero_pad, 1, 0);
	return (count);
}

int	print_integer(int n, t_flags *flags)
{
	int			count;
	long long	num;
	int			num_len;

	count = 0;
	num = n;
	if (num < 0)
		num_len = get_num_len(-num);
	else
		num_len = get_num_len(num);
	if (num == 0 && flags->precision == 0)
		return (print_width(flags->width, 0, flags->minus));
	count += print_integer_padding(num, num_len, flags);
	if (num != 0 || flags->precision != 0)
	{
		if (num < 0)
			ft_putnbr_ll(-num);
		else
			ft_putnbr_ll(num);
		count += num_len;
	}
	if (flags->minus && flags->width > count)
		count += print_width(flags->width - count, 0, 1);
	return (count);
}
