/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:17:24 by akihito           #+#    #+#             */
/*   Updated: 2022/11/26 20:05:27 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	is_float(char *str)
{
	bool	flag;
	char	*integer;
	char	*decimal;

	decimal = ft_strchr(str, '.');
	if (decimal)
		integer = ft_substr(str, 0, decimal - str);
	else
		integer = ft_strdup(str);
	if (integer == NULL)
		exit(1);
	flag = is_num(integer);
	free(integer);
	if (decimal == NULL)
		return (flag);
	if (decimal[1] == '\0')
		return (false);
	while (*(++decimal))
	{
		if (!ft_isdigit(*decimal))
			return (false);
	}
	return (flag);
}
