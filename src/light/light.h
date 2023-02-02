/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:07:16 by akihito           #+#    #+#             */
/*   Updated: 2022/12/04 16:23:10 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "../color/color.h"
# include "../vector_3d/vector_3d.h"

// light
typedef enum e_light_kind
{
	AMBIENT_LIGHT,
	LIGHT,
}	t_light_kind;

typedef struct s_light
{
	struct s_light	*next;
	t_light_kind	kind;

	double			intensity;
	t_color			color;
	t_vec_3d		pos;
}				t_light;

#endif /* LIGHT_H */
