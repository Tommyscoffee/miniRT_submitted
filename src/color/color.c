/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:06:35 by akihito           #+#    #+#             */
/*   Updated: 2022/11/26 20:06:36 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_color	color_standard(t_color a)
{
	return ((t_color){
		double_max(0.0, double_min(1.0, a.r)),
		double_max(0.0, double_min(1.0, a.g)),
		double_max(0.0, double_min(1.0, a.b))});
}
