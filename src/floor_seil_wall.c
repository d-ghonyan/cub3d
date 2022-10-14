/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_sell_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:29:21 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/14 19:15:12 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drow_floor_and_ceil(t_win *win)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT_WIN / 2)
	{
		j = 0;
		while (j < WIDTH_WIN)
		{
			ft_put_pixel(win, j, i, win->c_color);
			++j;
		}
		++i;
	}
	while (i < HEIGHT_WIN)
	{
		j = 0;
		while (j < WIDTH_WIN)
		{
			ft_put_pixel(win, j, i, win->f_color);
			++j;
		}
		++i;
	}
}
