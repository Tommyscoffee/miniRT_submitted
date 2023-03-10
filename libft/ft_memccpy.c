/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:28:34 by akihito           #+#    #+#             */
/*   Updated: 2022/12/05 15:28:35 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_chr;
	unsigned char	*src_chr;
	unsigned char	c_chr;

	dst_chr = (unsigned char *)dst;
	src_chr = (unsigned char *)src;
	c_chr = (unsigned char)c;
	while (n-- > 0)
	{
		if (*src_chr == c_chr)
		{
			*(dst_chr)++ = *src_chr;
			return ((void *)dst_chr);
		}
		*(dst_chr)++ = *(src_chr)++;
	}
	return (NULL);
}
