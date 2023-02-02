/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:23:24 by akihito           #+#    #+#             */
/*   Updated: 2022/12/04 23:29:19 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

double	double_max(double a, double b);
double	double_min(double a, double b);
void	error(char *str);
void	error_line_msg(long line, char *msg);
void	*ft_walloc(size_t count, size_t size, const char *func_name);
void	free_all(char **strs);
void	put_usage(void);
bool	is_num(char *str);
bool	is_float(char *str);

#endif
