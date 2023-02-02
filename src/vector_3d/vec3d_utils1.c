/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:25:33 by akihito           #+#    #+#             */
/*   Updated: 2022/12/04 14:25:35 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

double	vector_3d_length(t_vec_3d a)
{
	return (sqrt(vector_3d_dot(a, a)));
}

t_vec_3d	vector_3d_unit(t_vec_3d a)
{
	return (vector_3d_mult(a, 1.0 / vector_3d_length(a)));
}
