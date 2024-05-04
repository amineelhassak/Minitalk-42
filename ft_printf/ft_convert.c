/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 06:18:36 by amel-has          #+#    #+#             */
/*   Updated: 2023/11/10 10:53:53 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convox(unsigned	int n, const char *base, int *count, int *errorh)
{
	unsigned int		len;

	len = ft_strlen(base);
	if (*errorh == 1)
		return ;
	if (n >= 0 && n < len)
	{
		if (write(1, &base[n], 1) == -1)
			*errorh = 1;
		(*count)++;
	}
	else if (n >= len)
	{
		ft_convox(n / len, base, count, errorh);
		ft_convox(n % len, base, count, errorh);
	}
}

int	ft_convert(unsigned	int n, const char *base, int *count)
{
	int	errorh;

	errorh = 0;
	ft_convox(n, base, count, &errorh);
	if (errorh == 0)
		return (*count);
	else 
		return (-1);
}
