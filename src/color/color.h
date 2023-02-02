/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:06:38 by akihito           #+#    #+#             */
/*   Updated: 2022/11/26 20:06:38 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}				t_color;

int		convert_color(t_color c);
t_color	color_add_color(t_color a, t_color b);
t_color	color_add_num(t_color a, double num);
t_color	color_mult_color(t_color a, t_color b);
t_color	color_mult_num(t_color a, double num);
t_color	color_standard(t_color a);

#endif
