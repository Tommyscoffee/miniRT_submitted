/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:25:15 by akihito           #+#    #+#             */
/*   Updated: 2022/12/04 23:59:59 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "../color/color.h"
# include "../vector_3d/vector_3d.h"
# include <stdbool.h>

// shape
typedef enum e_shape_kind {
	SPHERE,
	PLANE,
	CYLINDER,
}	t_shape_kind;

typedef struct s_shape {
	struct s_shape	*next;
	t_shape_kind	kind;
	t_color			color;
	t_color			ka;
	t_color			kd;
	t_color			ks;
	double			shininess;
	t_vec_3d		center;
	double			radius;
	t_vec_3d		normal;
	t_vec_3d		point;
	double			height;
}	t_shape;

double		with_sphere(t_vec_3d o_to_screen, t_vec_3d o, t_shape *shape);
double		with_plane(t_vec_3d o_to_screen, t_vec_3d o, t_shape *shape);
double		with_cylinder(t_vec_3d o_to_screen, t_vec_3d o, t_shape *shape);
double		shape_get_intersection(t_vec_3d o_to_screen, t_vec_3d o, \
	t_shape *shape);
t_vec_3d	shape_normal_vec(t_shape *shape, t_vec_3d pos);

#endif /* SHAPE_H */
