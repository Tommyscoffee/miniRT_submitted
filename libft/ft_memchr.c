/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:28:37 by akihito           #+#    #+#             */
/*   Updated: 2022/12/05 15:28:37 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_char = s;
	const unsigned char	c_char = c;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (*(s_char + i) == c_char)
			return ((void *)(s_char + i));
		i++;
	}
	return (NULL);
}
