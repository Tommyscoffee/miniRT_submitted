/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:02:57 by akihito           #+#    #+#             */
/*   Updated: 2022/12/05 03:05:22 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#ifdef BONUS
# define BONUS_FLAG 1
#else
# define BONUS_FLAG 0
#endif

void	world_destuctor(t_world *world)
{
	t_light	*light;
	t_shape	*shape;

	light = world->light_list;
	while (light)
	{
		world->light_list = light->next;
		free(light);
		light = world->light_list;
	}
	shape = world->shape_list;
	while (shape)
	{
		world->shape_list = shape->next;
		free(shape);
		shape = world->shape_list;
	}
	free(world->camera);
	free(world);
}

void	world_check(t_world *world)
{
	t_light	*light;

	light = world->light_list;
	while (light)
	{
		if (light->kind == AMBIENT_LIGHT)
			world->a_cnt++;
		else
			world->l_cnt++;
		light = light->next;
	}
	if (!world->camera)
		error("Error :camera is not found");
	else if (world->a_cnt != 1)
		error("Error :wrong number of ambient light");
	else if ((BONUS_FLAG == 0 && world->l_cnt != 1)
		|| (BONUS_FLAG == 1 && world->l_cnt < 1))
		error("Error :wrong number of light");
}

t_world	*world_init(char *filename)
{
	const t_color	bg = (t_color){30.0, 30.0, 30.0};
	t_world			*world;
	int				fd;

	if (!check_filename(filename))
		error("Error:Not .rt extension");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error :open");
		exit(1);
	}
	world = ft_calloc(1, sizeof(t_world));
	if (!world)
	{
		printf("Error : malloc error\n");
		close(fd);
		exit(1);
	}
	world->bg = bg;
	world_parse(world, fd);
	world_check(world);
	close(fd);
	return (world);
}
