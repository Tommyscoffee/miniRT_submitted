/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:52:52 by akihito           #+#    #+#             */
/*   Updated: 2022/12/04 15:52:52 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	world_add_light(t_world *world, t_light *light)
{
	light->next = world->light_list;
	world->light_list = light;
}

void	world_add_shape(t_world *world, t_shape *shape)
{
	shape->next = world->shape_list;
	world->shape_list = shape;
}
