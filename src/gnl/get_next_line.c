/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:48:29 by akihito           #+#    #+#             */
/*   Updated: 2022/12/05 14:49:13 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	put_memo(char *str, char **memo)
{
	char	*tmp;
	int		i;

	i = -1;
	if (!*memo)
		tmp = (char *)malloc(ft_strlen(str) + 1);
	else
		tmp = (char *)malloc(ft_strlen(str) + ft_strlen(*memo) + 1);
	if (!tmp)
		return (-1);
	if (*memo)
	{
		while ((*memo)[++i])
			tmp[i] = (*memo)[i];
		free(*memo);
	}
	else
		i++;
	ft_strlcpy(&tmp[i], str, ft_strlen(str) + 1);
	*memo = ft_strdup(tmp);
	free(tmp);
	return (check_memo(*memo));
}

int	put_line(char **memo, char **line)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while ((*memo)[i] != '\n')
		i++;
	*line = (char *)malloc(sizeof(char) * (i + 1));
	if (!*line)
	{
		free(*memo);
		return (-1);
	}
	ft_strlcpy(*line, *memo, i + 1);
	tmp = *memo;
	*memo = ft_strdup(&(*memo)[i + 1]);
	if (*memo == NULL)
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	return (1);
}

int	check_memo(char *memo)
{
	if (!memo)
		return (0);
	if (ft_strchr(memo, '\n'))
		return (1);
	else
		return (0);
}

int	put_eof(char **memo, char **line)
{
	*line = ft_strdup(*memo);
	free(*memo);
	*memo = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*memo;
	char		*tmp;
	ssize_t		r_byte;
	int			flag;

	if (!line || fd < 0 || BUFFER_SIZE <= 0 || 256 < fd)
		return (-1);
	*line = NULL;
	flag = check_memo(memo);
	r_byte = 1;
	while (flag == 0 && r_byte != 0)
	{
		tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		r_byte = read(fd, tmp, BUFFER_SIZE);
		if (r_byte == -1)
			return (ft_free(&tmp, &memo));
		tmp[r_byte] = '\0';
		flag = put_memo(tmp, &memo);
		free(tmp);
	}
	if (r_byte == 0 && flag >= 0)
		flag = put_eof(&memo, line);
	else if (ft_strchr(memo, '\n') && flag >= 0)
		flag = put_line(&memo, line);
	return (flag);
}
