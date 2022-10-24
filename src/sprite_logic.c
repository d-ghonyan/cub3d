/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:41:24 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/22 17:17:19 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_calc_dist_height_wall_s(t_win *win)
{
	if (win->sprite.direction_dda)
		win->wall.distance = win->ray.dda.shift_y \
			- win->ray.dda.cell_distance_y;
	else
		win->wall.distance = win->ray.dda.shift_x \
			- win->ray.dda.cell_distance_x;
	win->wall.height = (int)(HEIGHT_WIN / win->wall.distance);
	win->wall.start_pixel = HEIGHT_WIN / 2 - win->wall.height / 2;
	if (win->wall.start_pixel < 0)
		win->wall.start_pixel = 0;
}

void	ft_calc_row_wall_s(t_win *win)
{
	double	column;

	if (win->ray.dda.direction_dda)
		column = win->player.position_x + win->wall.distance * \
        win->ray.direction_x;
	else
		column = win->player.position_y + win->wall.distance * \
        win->ray.direction_y;
	column -= floor(column);
	win->wall.column = (int)(column * 64);
}

void	ft_draw_wall_s(t_win *win)
{
	double	interpolation;
	int		color;
	int		i;
	int		r;
	int		*wall;

	i = 0;
	r = 0;
	wall = (int *)win->sprt.addr;
	win->wall.row = 0;
	if (win->wall.distance < 1)
		win->wall.row = (64.0 - 64.0 * win->wall.distance) / 2;
	interpolation = (double)64 / (double)win->wall.height;
	while (i < win->wall.height && i < HEIGHT_WIN)
	{
		color = wall[win->wall.row, (int)win->wall.column];
		ft_put_pixel(win, win->ray.number, \
			win->wall.start_pixel + i - r, color);
		win->wall.row += interpolation;
		++i;
	}
	win->ray.door = 0;
}
