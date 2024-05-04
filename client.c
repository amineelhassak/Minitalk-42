/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:31:38 by amel-has          #+#    #+#             */
/*   Updated: 2023/11/29 10:31:42 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putstr_fdd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		usleep(50000);
		s++;
	}
}

static int	ft_isalldigit(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

static int	shifre_bit(int pid, char c)
{
	int	count_shift;
	int	index;

	index = 0;
	count_shift = 0;
	while (count_shift < 8)
	{
		if ((c >> count_shift) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				index = 1;
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				index = 1;
		}
		if (index == 1)
			return (ft_putstr_fdd(MSG_ERRR, 2), 0);
		count_shift++;
		usleep(200);
	}
	return (1);
}

int	main(int c, char **v)
{
	int		i;
	pid_t	pid;

	if (c != 3 || !ft_isalldigit(v[1]))
	{
		ft_putstr_fdd(MSG_ER, 2);
		ft_putstr_fdd(MSG_DATAC, 2);
		ft_putstr_fdd(EXP_DATA, 2);
		return (1);
	}
	pid = ft_atoi(v[1]);
	if (ft_printf(PIDC, getpid()) < 0)
		return (ft_putstr_fdd(MSG_ERPPID, 2), -1);
	i = -1;
	while (v[2][++i])
	{
		if (!shifre_bit(pid, v[2][i]))
			return (0);
	}
	shifre_bit(pid, '\0');
	return (0);
}
