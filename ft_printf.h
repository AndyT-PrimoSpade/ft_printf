/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtan <andtan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 05:46:53 by andtan            #+#    #+#             */
/*   Updated: 2024/08/05 06:47:29 by andtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printpointer(void *pointer);
int	ft_printhex(unsigned int n, int is_case);
int	ft_printunsigned(unsigned int n);
int	ft_printstr(char *str);
int	ft_printint(int n);
int	ft_printchar(int c);
int	ft_printf(const char *s, ...);
int	format_handing(va_list args, const char s);

#endif
