/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtan <andtan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:27:41 by andtan            #+#    #+#             */
/*   Updated: 2024/08/18 08:38:56 by andtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_width(int width, int zero, int minus)
{
	int		count;
	char	c;

	count = 0;
	if (zero && !minus)
		c = '0';
	else
		c = ' ';
	while (width-- > 0)
		count += write(1, &c, 1);
	return (count);
}

int	print_char(int c, t_flags *flags)
{
	int	count;

	count = 0;
	if (!flags->minus && flags->width > 1)
		count += print_width(flags->width - 1, flags->zero, flags->minus);
	count += write(1, &c, 1);
	if (flags->minus && flags->width > 1)
		count += print_width(flags->width - 1, 0, flags->minus);
	return (count);
}
