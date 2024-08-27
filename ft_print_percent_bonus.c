/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtan <andtan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:39:33 by andtan            #+#    #+#             */
/*   Updated: 2024/08/18 07:42:35 by andtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_percent(t_flags *flags)
{
	int	count;

	count = 0;
	(void)flags;
	count += write(1, "%", 1);
	return (count);
}
