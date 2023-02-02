/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d_camera_to_screen.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:25:56 by akihito           #+#    #+#             */
/*   Updated: 2022/12/04 14:25:57 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_vec_3d	vector_3d_camera_to_screen(t_camera *camera, t_vec_3d to_screen)
{
	return (vector_3d_sub(to_screen, camera->pos));
}
