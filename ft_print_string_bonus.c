/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtan <andtan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 00:20:01 by andtan            #+#    #+#             */
/*   Updated: 2024/08/18 08:35:10 by andtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_string(char *s, t_flags *flags)
{
	int		count;
	int		print_len;
	char	*null_str;

	null_str = "(null)";
	count = 0;
	if (!s)
	{
		if (flags->precision >= 0 && flags->precision < 6)
			s = "";
		else
			s = null_str;
	}
	print_len = ft_strlen(s);
	if (flags->precision >= 0 && flags->precision < print_len)
		print_len = flags->precision;
	if (flags->precision == 0 && flags->point)
		print_len = 0;
	if (!flags->minus && flags->width > print_len)
		count += print_width(flags->width - print_len, flags->zero, 0);
	if (print_len > 0)
		count += write(1, s, print_len);
	if (flags->minus && flags->width > print_len)
		count += print_width(flags->width - print_len, 0, 1);
	return (count);
}
