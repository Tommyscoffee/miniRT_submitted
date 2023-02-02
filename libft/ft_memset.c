/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:28:46 by akihito           #+#    #+#             */
/*   Updated: 2022/12/05 15:28:47 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*s_chr_p;

	i = 0;
	s_chr_p = (char *)b;
	while (i < len)
	{
		*(s_chr_p + i) = (char)c;
		i++;
	}
	return (b);
}
