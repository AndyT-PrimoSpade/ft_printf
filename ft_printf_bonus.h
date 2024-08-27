/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtan <andtan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:21:57 by andtan            #+#    #+#             */
/*   Updated: 2024/08/18 09:35:28 by andtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int	width;
	int	precision;
	int	zero;
	int	minus;
	int	hash;
	int	space;
	int	plus;
	int	point;
}		t_flags;

int		print_hex(unsigned long n, int uppercase, t_flags *flags);
int		print_width(int width, int zero, int minus);
int		print_char(int c, t_flags *flags);
int		ft_printf(const char *format, ...);
int		handle_format(va_list args, const char **format);
void	init_flags(t_flags *flags);
void	parse_flags(const char **format, t_flags *flags);
int		print_string(char *s, t_flags *flags);
int		print_pointer(void *ptr, t_flags *flags);
int		print_integer(int n, t_flags *flags);
int		print_unsigned(unsigned int n, t_flags *flags);
int		print_hex(unsigned long n, int uppercase, t_flags *flags);
int		print_percent(t_flags *flags);
void	ft_putnbr_ll(long long n);

#endif
