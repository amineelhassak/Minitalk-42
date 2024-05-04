/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:41:20 by amel-has          #+#    #+#             */
/*   Updated: 2023/11/10 10:56:34 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbrd(long int n, int *count, int	*errorhandler)
{
	int				s;
	long int		nbr;

	nbr = n;
	s = 1;
	if (*errorhandler == 1)
		return ;
	if (nbr < 0)
	{
		(*count)++;
		if (write(1, "-", 1) == -1)
			*errorhandler = 1;
		nbr = -nbr;
	}
	if (nbr <= 9 && nbr >= 0)
	{
		if (write(1, &(char){nbr + '0'}, 1) == -1)
			*errorhandler = 1;
	}
	else
	{
		ft_putnbrd(nbr / 10, count, errorhandler);
		ft_putnbrd(nbr % 10, count, errorhandler);
		(*count)++;
	}
}

int	ft_putd(int n)
{
	int	count;
	int	errorhandler;

	errorhandler = 0;
	count = 1;
	ft_putnbrd(n, &count, &errorhandler);
	if (errorhandler == 1)
		return (-1);
	return (count);
}
