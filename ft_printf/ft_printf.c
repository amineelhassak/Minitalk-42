/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:43:46 by amel-has          #+#    #+#             */
/*   Updated: 2023/11/10 13:15:00 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	function1(char s, va_list p)
{
	int	x;

	x = 0;
	if (s == 'd')
		return (ft_putd(va_arg(p, int))); 
	else if (s == 'c')
		return (ft_putc(va_arg(p, int)));
	else if (s == 'u')
		return (ft_putu(va_arg(p, unsigned int)));
	else if (s == 'i') 
		return (ft_putd(va_arg(p, unsigned int)));
	else if (s == 'x')
		return (ft_convert(va_arg(p, unsigned int), "0123456789abcdef", &x));
	else if (s == 'X')
		return (ft_convert(va_arg(p, unsigned int), "0123456789ABCDEF", &x));
	else if (s == 'p')
		return (ft_putp(va_arg(p, unsigned long long), &x));
	else if (s == 's') 
		return (ft_puts(va_arg(p, const char *)));
	else if (s == '%')
		return (ft_putc('%'));
	return (0);
}

int	count_put(char s, va_list p, int *res)
{
	int	x;

	x = function1(s, p);
	if (x == -1)
		return (-1);
	*res += x;
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	p;
	int		len;

	len = 0;
	va_start(p, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (count_put(*s, p, &len) == -1)
				return (-1);
			if (*s)
				s++;
		}
		else if (*s)
		{
			if (ft_putc(*s) == -1)
				return (-1);
			(len)++;
			s++;
		}
	}
	return (len);
}
