/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 04:47:17 by amel-has          #+#    #+#             */
/*   Updated: 2023/11/04 04:49:31 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	n;
	int	size;

	if (!s1 || !set)
		return (0);
	if (!(*s1))
		return (ft_strdup(""));
	i = 0;
	n = ft_strlen(s1);
	n--;
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	while (ft_strchr(set, s1[n]) && s1[n])
		n--;
	size = n - i + 1;
	return (ft_substr(s1, i, size)); 
}
/*
int main()
{
	printf("%s",ft_strtrim("amineam","am"));
	printf("\n");
	printf("%s hi man",ft_strtrim("",""));
	printf("%s \n",ft_strtrim("","hi"));
	printf("%s",ft_strtrim("hi", ""));

}*/
