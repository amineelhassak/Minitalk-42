/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:31:19 by amel-has          #+#    #+#             */
/*   Updated: 2023/11/29 10:31:23 by amel-has         ###   ########.fr       */
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

static void	handel_unicode(unsigned char c, int *ind)
{
	static unsigned char	t[4];
	static int				index;
	static int				nbrbyte;

	if (*ind == 1)
	{
		index = 0;
		nbrbyte = 0;
		ft_memset(t, 0, 4);
		*ind = 0;
	}
	if (c >= 192 && c <= 223)
		nbrbyte = 2;
	else if (c >= 224 && c <= 239)
		nbrbyte = 3;
	else if (c >= 240)
		nbrbyte = 4;
	t[index++] = c;
	if (index == nbrbyte)
	{
		write(1, t, nbrbyte);
		(0 == 0) && (index = 0, nbrbyte = 0, ft_memset(t, 0, 4)); 
	}
}

static void	bit_handler(int signal, siginfo_t *siginfo, void *vd)
{
	static int				pid_c;
	static unsigned char	i;
	static int				count;
	static int				index;

	(void)vd;
	if (pid_c != siginfo->si_pid)
		(1 == 1) && (count = 0, i = 0, pid_c = siginfo->si_pid, index = 1);
	if (signal == SIGUSR1)
		i |= 0x01 << count;
	count++;
	if (count == 8)
	{
		if (i <= 127)
			ft_putchar_fd(i, 1);
		else
			handel_unicode(i, &index);
		(1 == 1) && (count = 0, i = 0);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putstr_fdd(MSG_FC, 1);
	if (ft_printf(PIDS, pid) < 0)
		ft_putstr_fdd(MSG_ERPPID, 2);
	ft_putstr_fdd(CHEV, 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = bit_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
