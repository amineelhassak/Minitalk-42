/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:44:19 by amel-has          #+#    #+#             */
/*   Updated: 2023/11/10 12:33:48 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puts(const char *str)
{
	int		i;
	int		n;
	char	*s;

	s = "(null)";
	n = 0;
	i = 0;
	if (str == NULL)
	{
		while (i < 6)
		{
			if (ft_putc(s[i]) == -1)
				return (-1);
			i++;
		}
		return (6);
	}
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (ft_strlen(str));
}
