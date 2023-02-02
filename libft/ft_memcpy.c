/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:28:42 by akihito           #+#    #+#             */
/*   Updated: 2022/12/05 15:32:32 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_chr;
	const char	*src_chr;

	dst_chr = (char *)dst;
	src_chr = (const char *)src;
	if (!dst_chr && !src_chr)
		return (NULL);
	while (n-- > 0)
	{
		*(dst_chr++) = *(src_chr++);
	}
	return (dst);
}
