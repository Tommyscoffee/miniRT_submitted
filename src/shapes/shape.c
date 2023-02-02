/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:07:22 by akihito           #+#    #+#             */
/*   Updated: 2022/11/26 20:16:36 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

double	shape_get_intersection(t_vec_3d o_to_screen, t_vec_3d o, t_shape *shape)
{
	if (shape->kind == SPHERE)
		return (with_sphere(o_to_screen, o, shape));
	if (shape->kind == PLANE)
		return (with_plane(o_to_screen, o, shape));
	if (shape->kind == CYLINDER)
		return (with_cylinder(o_to_screen, o, shape));
	return (0.0);
}
