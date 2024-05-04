/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:41:40 by amel-has          #+#    #+#             */
/*   Updated: 2023/11/29 13:41:09 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "../mylibft/libft.h"

int	ft_printf(const char *s, ...);
int	ft_putc(int c);
int	ft_putd(int n);
int	ft_convert(unsigned	int n, const char *base, int *count);
int	ft_puts(const char *str);
int	ft_putu(unsigned int n);
int	ft_putp(unsigned long long n, int *x);
#endif
