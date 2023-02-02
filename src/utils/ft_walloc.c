/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:12:38 by akihito           #+#    #+#             */
/*   Updated: 2022/12/05 03:04:30 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_walloc(size_t count, size_t size, const char *func_name)
{
	size_t	ratio;
	size_t	len;
	void	*ptr;

	if (count == 0)
		count = 1;
	if (size == 0)
		size = 1;
	ratio = ULONG_MAX / size;
	if (count > ratio)
		len = ULONG_MAX;
	else
		len = size * count;
	ptr = malloc(len);
	if (ptr == NULL)
	{
		printf("Error :in %s, failed to malloc\nError :", func_name);
		exit(1);
	}
	return (ptr);
}
