/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:09:30 by akihito           #+#    #+#             */
/*   Updated: 2022/12/05 15:33:34 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

typedef struct s_vector_3d	t_vec_3d;

typedef struct s_camera {
	t_vec_3d	pos;
	t_vec_3d	normal;
	double		fov;

	t_vec_3d	screen_start_pos;
	t_vec_3d	screen_vertical_normal;
	t_vec_3d	screen_horizon_normal;
	double		screen_height;
	double		screen_width;
	double		dx;
	double		dy;
}	t_camera;

void	camera_set(t_camera *camera);

#endif /* CAMERA_H */
