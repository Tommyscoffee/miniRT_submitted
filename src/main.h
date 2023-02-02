/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 00:04:01 by akihito           #+#    #+#             */
/*   Updated: 2022/12/06 00:16:05 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define WIDTH 900
# define HEIGHT 900

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "gnl/get_next_line.h"
# include "vector_3d/vector_3d.h"
# include "color/color.h"
# include "world/world.h"
# include "compute/compute.h"
# include "display/display.h"
# include "utils/utils.h"

enum	e_x11_events {
	X11_ON_DESTROY = 17,
};

enum	e_x11_masks {
	X11_STRUCTURE_NOTIFY_MASK = (1L << 17),
};

typedef struct s_compute {
	t_shape		*shape;
	t_light		*light;
	t_vec_3d	o_to_screen;
	t_vec_3d	intersected_pos;
	t_vec_3d	pos_to_light_dir;
	t_vec_3d	intersected_pos_normal;
	t_vec_3d	reverse_eye_dir;
	double		cosin_a;
	t_color		light_color;
}	t_compute;

typedef struct s_all_info
{
	t_world		*world;
	t_display	*display;
}	t_all_info;

int	key_event(int key_code, void *param);
int	click_cross_event(void *param);

#endif /* MINIRT_H */
