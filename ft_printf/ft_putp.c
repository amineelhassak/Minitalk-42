/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:19:55 by amel-has          #+#    #+#             */
/*   Updated: 2023/11/10 13:05:46 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv(unsigned long long n, const char *base, int *count, int *erroh)
{
	unsigned long long	len;

	len = ft_strlen(base);
	if (*erroh == 1)
		return ;
	if (n < len && n >= 0)
	{
		if (write(1, &base[n], 1) == -1)
			*erroh = 1;
		(*count)++;
	}
	else if (n >= len)
	{
		ft_conv(n / len, base, count, erroh);
		ft_conv(n % len, base, count, erroh);
	}
}

int	ft_putp(unsigned long long n, int *x)
{
	int		errohandler;

	if (ft_puts("0x") == -1)
		return (-1);
	errohandler = 0;
	ft_conv(n, "0123456789abcdef", x, &errohandler);
	if (errohandler == 1)
		return (-1);
	return (*x + 2);
}
