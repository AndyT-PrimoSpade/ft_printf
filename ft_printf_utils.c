/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtan <andtan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 05:49:12 by andtan            #+#    #+#             */
/*   Updated: 2024/08/05 07:00:12 by andtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printpointer(void *pointer)
{
	unsigned long	n;
	int				print;
	char			*hex;

	print = 0;
	n = (unsigned long)pointer;
	hex = "0123456789abcdef";
	if (n == 0)
		return (write(1, "(nil)", 5));
	if (n >= 16)
		print += ft_printpointer((void *)(n / 16));
	if (n < 16)
		print += write(1, "0x", 2);
	print += write(1, &hex[n % 16], 1);
	return (print);
}

int	ft_printhex(unsigned int n, int is_case)
{
	char	*hex;
	int		print;

	print = 0;
	if (is_case)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
		print += ft_printhex(n / 16, is_case);
	print += write(1, &hex[n % 16], 1);
	return (print);
}

int	ft_printunsigned(unsigned int n)
{
	char	c;
	int		print;

	print = 0;
	if (n >= 10)
		print += ft_printunsigned(n / 10);
	c = n % 10 + '0';
	print += write(1, &c, 1);
	return (print);
}

int	ft_printstr(char *str)
{
	int	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	return (write(1, str, len));
}

int	ft_printint(int n)
{
	char	*num;
	int		print;

	num = ft_itoa(n);
	print = ft_printstr(num);
	free(num);
	return (print);
}
