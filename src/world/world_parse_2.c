/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_parse_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:52:54 by akihito           #+#    #+#             */
/*   Updated: 2022/12/04 23:29:39 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	world_parse_sphere(t_world *world, char **strs, long row)
{
	const long	len = ft_strs_count(strs);
	t_shape		*shape;

	if (len != 4)
		error_line_msg(row, "wrong number of elements");
	shape = (t_shape *)ft_walloc(sizeof(t_shape), 1, __func__);
	shape->kind = SPHERE;
	shape->center = parse_vector_3d(strs[1], row);
	shape->radius = parse_positive_num(strs[2], row) / 2.0;
	shape->color = parse_color(strs[3], row);
	shape->ka = color_mult_num(shape->color, 1.0 / 255.0);
	shape->kd = color_mult_num(shape->color, 1.0 / 255.0 * 0.69);
	shape->ks = (t_color){0.3, 0.3, 0.3};
	shape->shininess = 16.0;
	world_add_shape(world, shape);
}

void	world_parse_plane(t_world *world, char **strs, long row)
{
	const long	len = ft_strs_count(strs);
	double		*tmp;
	t_shape		*shape;

	if (len != 4)
		error_line_msg(row, "wrong number of elements");
	shape = (t_shape *)ft_walloc(sizeof(t_shape), 1, __func__);
	shape->kind = PLANE;
	shape->point = parse_vector_3d(strs[1], row);
	shape->normal = parse_vector_3d(strs[2], row);
	tmp = (double []){shape->normal.x, shape->normal.y, shape->normal.z};
	if (!check_in_range(tmp, 3, 1.0, -1.0) || \
			vector_3d_length(shape->normal) == 0)
		error_line_msg(row, "normal has wrong vector");
	shape->normal = vector_3d_unit(shape->normal);
	shape->color = parse_color(strs[3], row);
	shape->ka = color_mult_num(shape->color, 1.0 / 255.0);
	shape->kd = color_mult_num(shape->color, 1.0 / 255.0 * 0.69);
	shape->ks = (t_color){0.3, 0.3, 0.3};
	shape->shininess = 16.0;
	world_add_shape(world, shape);
}

void	world_parse_cylinder(t_world *world, char **strs, long row)
{
	const long	len = ft_strs_count(strs);
	double		*tmp;
	t_shape		*shape;

	if (len != 6)
		error_line_msg(row, "wrong number of elements");
	shape = (t_shape *)ft_walloc(sizeof(t_shape), 1, __func__);
	shape->kind = CYLINDER;
	shape->normal = parse_vector_3d(strs[2], row);
	tmp = (double []){shape->normal.x, shape->normal.y, shape->normal.z};
	if (!check_in_range(tmp, 3, 1.0, -1.0) || \
			vector_3d_length(shape->normal) == 0)
		error_line_msg(row, "normal has wrong vector");
	shape->normal = vector_3d_unit(shape->normal);
	shape->radius = parse_positive_num(strs[3], row) / 2.0;
	shape->height = parse_positive_num(strs[4], row);
	shape->color = parse_color(strs[5], row);
	shape->center = parse_vector_3d(strs[1], row);
	shape->center = vector_3d_add(
			shape->center, vector_3d_mult(shape->normal, shape->height / 2.0));
	shape->ka = color_mult_num(shape->color, 1.0 / 255.0);
	shape->kd = color_mult_num(shape->color, 1.0 / 255.0 * 0.69);
	shape->ks = (t_color){0.3, 0.3, 0.3};
	shape->shininess = 16.0;
	world_add_shape(world, shape);
}
