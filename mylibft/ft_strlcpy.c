/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:10:02 by amel-has          #+#    #+#             */
/*   Updated: 2023/11/01 20:16:14 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	cpy_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	if (src_len <= dstsize - 1)
		cpy_len = src_len;
	else
		cpy_len = dstsize - 1;
	ft_memcpy(dst, src, cpy_len);
	dst[cpy_len] = '\0';
	return (src_len);
}
