/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:53:27 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/20 18:57:40 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_enter_doors(t_win *win)
{
	int	i;
	int	j;

	i = 1;
	while (i < ft_spllen(win->map))
	{
		j = 0;
		while (win->map[i][j])
		{
			if ('0' == win->map[i][j] && j >= 1 && j < ft_strlen(win->map[i]) \
				&& '1' == win->map[i][j + 1] && '1' == win->map[i][j - 1] && \
				'0' == win->map[i - 1][j] && '0' == win->map[i + 1][j])
				win->map[i][j] = 'd';
			++j;
		}
		++i;
	}
	store_xpm(&win->door, win->mlx, "xpm/door.xpm");
	ft_putendl_fd("[Log] Door texture defined", 1);
}
