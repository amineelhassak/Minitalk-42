/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:13:51 by amel-has          #+#    #+#             */
/*   Updated: 2023/11/03 18:15:38 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static void *function1(void *x)
{
	*(int *)x = 1;
	return x;
}

static void del(void *x)
{
	x = 0;
	free(x);
}
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new ;

	new = 0;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}

/*
int main()
{
	int i=0;
	int tab[10];
	t_list *list;
	t_list *li = 0;
	list = 0;
	while (i < 10)
	{
		printf("veuillez entre l'element N %d :",i);
		scanf("%d",&tab[i]);
		ft_lstadd_back(&list,ft_lstnew(&tab[i]));
		i++;
	}
	afficheListe(list);
	li = ft_lstmap(list,function1,del);
	afficheListe(list);
	return (0);
}*/