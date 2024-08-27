/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtan <andtan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 05:46:06 by andtan            #+#    #+#             */
/*   Updated: 2024/08/05 06:52:52 by andtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_printchar(int c)
{
	return (write(1, &c, 1));
}

int	format_handing(va_list args, const char s)
{
	int	print;

	print = 0;
	if (s == 'c')
		print = ft_printchar(va_arg(args, int));
	else if (s == 's')
		print = ft_printstr(va_arg(args, char *));
	else if (s == 'p')
		print = ft_printpointer(va_arg(args, void *));
	else if (s == 'd' || s == 'i')
		print = ft_printint(va_arg(args, int));
	else if (s == 'u')
		print = ft_printunsigned(va_arg(args, unsigned int));
	else if (s == 'x' || s == 'X')
		print = ft_printhex(va_arg(args, unsigned int), s == 'X');
	else if (s == '%')
		print = write(1, "%", 1);
	return (print);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	va_start(args, *s);
	count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			count += format_handing(args, *s);
		}
		else
			count += write(1, s, 1);
		s++;
	}
	va_end(args);
	return (count);
}
