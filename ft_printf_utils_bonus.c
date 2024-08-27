/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtan <andtan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 06:32:28 by andtan            #+#    #+#             */
/*   Updated: 2024/08/18 09:35:15 by andtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putnbr_ll(long long n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_ll(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	init_flags(t_flags *flags)
{
	flags->width = 0;
	flags->precision = -1;
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->point = 0;
}

static void	parse_precision(const char **format, t_flags *flags)
{
	flags->point = 1;
	flags->precision = 0;
	(*format)++;
	while (ft_isdigit(**format))
	{
		flags->precision = flags->precision * 10 + (**format - '0');
		(*format)++;
	}
	(*format)--;
}

static void	parse_width(const char **format, t_flags *flags)
{
	flags->width = 0;
	while (ft_isdigit(**format))
	{
		flags->width = flags->width * 10 + (**format - '0');
		(*format)++;
	}
	(*format)--;
}

void	parse_flags(const char **format, t_flags *flags)
{
	while (**format == '-' || **format == '0' || **format == '+'
		|| **format == ' ' || **format == '#' || **format == '.'
		|| ft_isdigit(**format))
	{
		if (**format == '-')
			flags->minus = 1;
		else if (**format == '0' && flags->width == 0 && flags->precision == -1)
			flags->zero = 1;
		else if (**format == '+')
			flags->plus = 1;
		else if (**format == ' ')
			flags->space = 1;
		else if (**format == '#')
			flags->hash = 1;
		else if (**format == '.')
			parse_precision(format, flags);
		else if (ft_isdigit(**format))
			parse_width(format, flags);
		(*format)++;
	}
}
