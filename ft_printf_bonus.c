/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtan <andtan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:26:51 by andtan            #+#    #+#             */
/*   Updated: 2024/08/05 06:32:13 by andtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	handle_format(va_list args, const char **format)
{
	t_flags	flags;
	int		count;

	init_flags(&flags);
	parse_flags(format, &flags);
	count = 0;
	if (**format == 'c')
		count = print_char(va_arg(args, int), &flags);
	else if (**format == 's')
		count = print_string(va_arg(args, char *), &flags);
	else if (**format == 'p')
		count = print_pointer(va_arg(args, void *), &flags);
	else if (**format == 'd' || **format == 'i')
		count = print_integer(va_arg(args, int), &flags);
	else if (**format == 'u')
		count = print_unsigned(va_arg(args, unsigned int), &flags);
	else if (**format == 'x' || **format == 'X')
		count = print_hex(va_arg(args, unsigned int), **format == 'X', &flags);
	else if (**format == '%')
		count = print_percent(&flags);
	(*format)++;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += handle_format(args, &format);
		}
		else
			count += write(1, format++, 1);
	}
	va_end(args);
	return (count);
}
