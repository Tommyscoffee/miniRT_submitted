/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:03:12 by akihito           #+#    #+#             */
/*   Updated: 2022/12/04 14:03:21 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

double	vector_3d_dot(t_vec_3d a, t_vec_3d b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec_3d	vector_3d_cross(t_vec_3d a, t_vec_3d b)
{
	return ((t_vec_3d){
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	});
}

t_vec_3d	vector_3d_sub(t_vec_3d a, t_vec_3d b)
{
	t_vec_3d	ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	return (ret);
}

t_vec_3d	vector_3d_add(t_vec_3d a, t_vec_3d b)
{
	t_vec_3d	ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	return (ret);
}

t_vec_3d	vector_3d_mult(t_vec_3d a, double n)
{
	return ((t_vec_3d){a.x * n, a.y * n, a.z * n});
}
