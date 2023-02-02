/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:25:09 by akihito           #+#    #+#             */
/*   Updated: 2022/12/04 14:25:10 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	convert_color(t_color c)
{
	return ((int)c.r << 16 | (int)c.g << 8 | (int)c.b);
}

t_color	color_add_color(t_color	a, t_color b)
{
	return ((t_color){a.r + b.r, a.g + b.g, a.b + b.b});
}

t_color	color_add_num(t_color a, double num)
{
	return ((t_color){a.r + num, a.g + num, a.b + num});
}

t_color	color_mult_color(t_color a, t_color b)
{
	return ((t_color){a.r * b.r, a.g * b.g, a.b * b.b});
}

t_color	color_mult_num(t_color a, double num)
{
	return ((t_color){a.r * num, a.g * num, a.b * num});
}
