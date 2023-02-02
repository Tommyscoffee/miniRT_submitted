/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:28:55 by akihito           #+#    #+#             */
/*   Updated: 2022/12/05 15:28:55 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	ans;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ans = (unsigned int)(n * -1);
	}
	else
		ans = (unsigned int)n;
	if (ans >= 10)
		ft_putnbr_fd(ans / 10, fd);
	ft_putchar_fd((char)(ans % 10 + '0'), fd);
}
