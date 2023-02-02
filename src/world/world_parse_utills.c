/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_parse_utills.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:02:49 by akihito           #+#    #+#             */
/*   Updated: 2022/12/06 21:12:54 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

bool	check_in_range(double val[], size_t len, double max, double min)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (val[i] < min || max < val[i])
			return (false);
		i++;
	}
	return (true);
}

bool	check_comma_cnt(char *str)
{
	char	*comma;
	long	cnt;

	cnt = 0;
	comma = str;
	while (true)
	{
		comma = ft_strchr(comma, ',');
		if (comma == NULL)
			break ;
		comma++;
		cnt++;
	}
	return (cnt == 2);
}

bool	check_elements(char **strs, t_check kind)
{
	const size_t	size = ft_strs_count(strs);
	size_t			i;

	if (size != 3)
		return (false);
	i = 0;
	while (i < size)
	{
		if (kind == INTEGER && !is_num(strs[i]))
			return (false);
		else if (kind == FLOAT && !is_float(strs[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	check_filename(char *filename)
{
	size_t	file_len;
	size_t	len;
	char	**splited_file;
	size_t	i;

	i = 0;
	file_len = ft_strlen(filename);
	splited_file = ft_split(filename, '/');
	while (splited_file[i])
		i++;
	len = ft_strlen(splited_file[i - 1]);
	if (len < 4)
	{
		while (i > 0)
		{
			free(splited_file[--i]);
		}
		free(splited_file);
		return (false);
	}
	return (!ft_strncmp(&filename[file_len - 3], ".rt", 4));
}
