/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:48:26 by akihito           #+#    #+#             */
/*   Updated: 2022/12/05 14:49:58 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		put_memo(char *str, char **memo);
int		put_line(char **memo, char **line);
int		check_memo(char *memo);
int		put_eof(char **memo, char **line);
int		get_next_line(int fd, char **line);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int		ft_free(char **tmp, char **memo);
char	*ft_strdup(const char *s1);
#endif
