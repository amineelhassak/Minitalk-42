/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:54:52 by amel-has          #+#    #+#             */
/*   Updated: 2023/11/04 01:29:20 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (dstsize == 0 && dst == NULL)
		return (len_src);
	len_dst = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= len_dst)
		return (len_src + dstsize);
	while (src[i] && i < dstsize - len_dst - 1)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
/*
int main()
{
    // char dest[10]="ami";
    printf("%zu",ft_strlcat(NULL ,"fkjgkfjg",0));
}*/
