/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:09:30 by akihito           #+#    #+#             */
/*   Updated: 2022/12/05 03:04:30 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include <stdio.h>

void	error(char *str)
{
	printf("%s\n", str);
	exit(1);
}

void	error_line_msg(long row, char *msg)
{
	printf("Error :in %ld: %s\n", row, msg);
	exit(1);
}
