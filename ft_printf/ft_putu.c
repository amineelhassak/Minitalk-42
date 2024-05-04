/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:22:25 by amel-has          #+#    #+#             */
/*   Updated: 2023/11/10 10:54:36 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putnbru(unsigned int n, int *count, int *errorh)
{
	int				s;

	s = 1;
	if (*errorh == 1)
		return ;
	if (n <= 9 && n >= 0)
	{
		if (write(1, &(char){n + '0'}, 1) == -1)
			*errorh = 1;
	}
	else
	{
		ft_putnbru(n / 10, count, errorh);
		ft_putnbru(n % 10, count, errorh);
		(*count)++;
	}
}

int	ft_putu(unsigned int n)
{
	int	count;
	int	errorh;

	count = 1;
	errorh = 0;
	ft_putnbru(n, &count, &errorh);
	if (errorh == 0)
		return (count);
	return (-1);
}
