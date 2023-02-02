/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:02:07 by akihito           #+#    #+#             */
/*   Updated: 2022/12/05 15:35:33 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_3D_H
# define VECTOR_3D_H

typedef struct s_camera	t_camera;
typedef struct s_shape	t_shape;

typedef struct s_vector_3d {
	double	x;
	double	y;
	double	z;
}	t_vec_3d;

t_vec_3d	vector_3d_cross(t_vec_3d a, t_vec_3d b);
t_vec_3d	vector_3d_camera_to_screen(t_camera *camera, t_vec_3d to_screen);
t_vec_3d	vector_3d_sp_center(t_shape *shape);
double		vector_3d_dot(t_vec_3d a, t_vec_3d b);
t_vec_3d	vector_3d_camera(t_camera *camera);
t_vec_3d	vector_3d_add(t_vec_3d a, t_vec_3d b);
double		vector_3d_length(t_vec_3d a);
t_vec_3d	vector_3d_sub(t_vec_3d a, t_vec_3d b);
t_vec_3d	vector_3d_unit(t_vec_3d a);
t_vec_3d	vector_3d_mult(t_vec_3d a, double n);

#endif
