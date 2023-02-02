/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:23:24 by akihito           #+#    #+#             */
/*   Updated: 2022/11/26 20:05:15 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	is_num(char *str)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	i = 0;
	if (len == 0)
		return (false);
	if ((str[i] == '+' || str[i] == '-')
		&& ft_isdigit(str[i + 1]))
		i++;
	while (i < len)
		if (!ft_isdigit(str[i++]))
			return (false);
	return (true);
}
