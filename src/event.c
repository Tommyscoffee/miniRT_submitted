/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:33:41 by akihito           #+#    #+#             */
/*   Updated: 2022/12/06 21:10:44 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	destruct_all(t_all_info *all)
{
	world_destuctor(all->world);
	display_destruct(all->display);
}

int	key_event(int key_code, void *param)
{
	if (key_code == 65307)
	{
		destruct_all(param);
		exit(0);
	}
	return (0);
}

int	click_cross_event(void *param)
{
	destruct_all(param);
	exit(0);
	return (0);
}
