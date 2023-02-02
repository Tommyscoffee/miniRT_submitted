/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:06:46 by akihito           #+#    #+#             */
/*   Updated: 2022/12/05 00:02:30 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_shape		*compute_intersected_shape(t_world *world, t_vec_3d to_screen);
t_color		compute_ambient_light(t_shape *shape, t_light *light);
t_vec_3d	compute_intersected_pos(\
			t_camera *camera, t_vec_3d to_screen, t_shape *shape);
bool		compute_is_shadow(t_world *world, t_light *light, \
			t_vec_3d intersected_pos);
void		set_t_compute(t_world *world, t_vec_3d to_screen, t_compute *c);

t_color	compute_specular(t_compute *c)
{
	t_color		rad_spe;
	t_vec_3d	r;

	rad_spe = (t_color){0, 0, 0};
	if (c->cosin_a > 0)
	{
		r = vector_3d_sub(
				vector_3d_mult(c->intersected_pos_normal,
					2 * (c->cosin_a)), c->pos_to_light_dir);
		rad_spe = color_mult_num(
				color_mult_color(c->shape->ks, c->light_color),
				pow(double_max(vector_3d_dot(c->reverse_eye_dir, r), 0.0),
					c->shape->shininess));
	}
	return (rad_spe);
}

t_color	compute_diffuse(t_compute *c)
{
	t_color	rad_dif;

	rad_dif = color_mult_num(color_mult_color \
		(c->shape->kd, c->light_color), c->cosin_a);
	return (rad_dif);
}

t_color	compute_light(
	t_world *world, t_vec_3d to_screen, t_shape *shape, t_light *light)
{
	t_color		color;
	t_compute	c;

	color = (t_color){0.0, 0.0, 0.0};
	c.shape = shape;
	c.light = light;
	c.intersected_pos = \
			compute_intersected_pos(world->camera, to_screen, shape);
	if (compute_is_shadow(world, light, c.intersected_pos))
		return ((t_color){0.0, 0.0, 0.0});
	set_t_compute(world, to_screen, &c);
	color = color_add_color(color, compute_diffuse(&c));
	color = color_add_color(color, compute_specular(&c));
	return (color);
}

t_color	compute_brightness(t_world *world, t_vec_3d to_screen, t_shape *shape)
{
	t_color	intensity;
	t_color	add_intensity;
	t_light	*now_light;

	if (shape == NULL)
		return ((t_color){0.0, 0.0, 0.0});
	intensity = (t_color){0.0, 0.0, 0.0};
	now_light = world->light_list;
	while (now_light)
	{
		if (now_light->kind == AMBIENT_LIGHT)
			add_intensity = compute_ambient_light(shape, now_light);
		if (now_light->kind == LIGHT)
			add_intensity = compute_light(world, to_screen, shape, now_light);
		intensity = color_add_color(intensity, add_intensity);
		now_light = now_light->next;
	}
	return (intensity);
}

t_color	compute_color_of_pixel(t_world *world, t_vec_3d to_screen)
{
	t_shape	*intersected_shape;
	t_color	color;

	intersected_shape = compute_intersected_shape(world, to_screen);
	if (intersected_shape == NULL)
		return (world->bg);
	color = compute_brightness(world, to_screen, intersected_shape);
	color = color_standard(color);
	color = color_mult_num(color, 255.0);
	return (color);
}
