/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:06:01 by amel-has          #+#    #+#             */
/*   Updated: 2023/10/31 22:06:18 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*li;

	li = (t_list *)malloc(sizeof(t_list));
	if (!li)
		return (0);
	li->content = content;
	li->next = NULL;
	return (li);
}
