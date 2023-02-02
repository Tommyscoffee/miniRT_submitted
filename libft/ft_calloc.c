/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:27:34 by akihito           #+#    #+#             */
/*   Updated: 2022/12/05 15:27:46 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	n;
	void	*ans;

	n = count * size;
	ans = malloc(n);
	if (ans == 0)
		return (NULL);
	ft_bzero(ans, n);
	return (ans);
}
