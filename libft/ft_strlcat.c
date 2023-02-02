/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:29:24 by akihito           #+#    #+#             */
/*   Updated: 2022/12/05 15:32:39 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	j;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		src_len += dstsize;
	else
		src_len += dst_len;
	j = 0;
	while (src[j] != '\0' && dst_len + 1 < dstsize)
	{
		dst[dst_len] = src[j];
		dst_len++;
		j++;
	}
	dst[dst_len] = '\0';
	return (src_len);
}
