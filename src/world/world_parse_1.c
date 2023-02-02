/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_parse_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:52:41 by akihito           #+#    #+#             */
/*   Updated: 2022/12/05 18:30:24 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include "../gnl/get_next_line.h"

void	world_parse_line(t_world *world, char *line, long row)
{
	char	**strs;

	strs = ft_split(line, ' ');
	if (strs == NULL)
		error(strerror(errno));
	else if (strs[0])
	{
		if (ft_strcmp(strs[0], "A") == 0)
			world_parse_ambient_light(world, strs, row);
		else if (ft_strcmp(strs[0], "C") == 0)
			world_parse_camera(world, strs, row);
		else if (ft_strcmp(strs[0], "L") == 0)
			world_parse_light(world, strs, row);
		else if (ft_strcmp(strs[0], "sp") == 0)
			world_parse_sphere(world, strs, row);
		else if (ft_strcmp(strs[0], "pl") == 0)
			world_parse_plane(world, strs, row);
		else if (ft_strcmp(strs[0], "cy") == 0)
			world_parse_cylinder(world, strs, row);
		else
			error_line_msg(row, "not exist keyword");
	}
	free_all(strs);
}

void	world_parse(t_world *world, int fd)
{
	char	*line;
	long	row;
	int		is_nextline;

	is_nextline = 1;
	row = 1;
	while (is_nextline)
	{
		is_nextline = get_next_line(fd, &line);
		if (line == NULL)
			break ;
		else if (line[0] != '\0' && line[0] != '#')
			world_parse_line(world, line, row);
		free(line);
		row++;
	}
}
