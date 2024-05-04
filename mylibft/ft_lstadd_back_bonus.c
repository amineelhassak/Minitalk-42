/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:29:38 by amel-has          #+#    #+#             */
/*   Updated: 2023/11/03 18:17:56 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*li;

	if (!new)
		return ;
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	li = ft_lstlast(*alst);
	li->next = new;
}
