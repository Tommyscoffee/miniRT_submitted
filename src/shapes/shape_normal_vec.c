/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_normal_vec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:25:44 by akihito           #+#    #+#             */
/*   Updated: 2022/12/04 16:23:43 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_vec_3d	shape_normal_vec(t_shape *shape, t_vec_3d pos)
{
	t_vec_3d	normal;

	normal = (t_vec_3d){0, 0, 0};
	if (shape->kind == SPHERE)
		normal = vector_3d_sub(pos, shape->center);
	else if (shape->kind == PLANE)
		normal = shape->normal;
	else if (shape->kind == CYLINDER)
	{
		normal = vector_3d_cross(vector_3d_sub(pos, shape->center), \
		shape->normal);
		normal = vector_3d_cross(shape->normal, normal);
		if (vector_3d_length(normal) == 0.0)
			normal = shape->normal;
	}
	return (vector_3d_unit(normal));
}
