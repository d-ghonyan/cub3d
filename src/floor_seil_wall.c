/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_seil_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:29:21 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/15 14:01:19 by mtiesha          ###   ########.fr       */
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

void	ft_calc_dist_height_wall(t_win *win)
{
	if (win->ray.dda.direction_dda)
		win->wall.distance = win->ray.dda.shift_y \
			- win->ray.dda.cell_distance_y;
	else
		win->wall.distance = win->ray.dda.shift_x \
			- win->ray.dda.cell_distance_x;
	win->wall.height = (int)(HEIGHT_WIN / win->wall.distance);
	win->wall.start_pixel = HEIGHT_WIN / 2 - win->wall.height / 2;
}

void	ft_calc_row_wall(t_win *win)
{
	double	column;

	if (win->ray.dda.direction_dda)
		column = win->player.position_x + win->wall.distance * \
        win->ray.direction_x;
	else
		column = win->player.position_y + win->wall.distance * \
        win->ray.direction_y;
	column -= floor(column);
	win->wall.row = (int)(column * 64);
	if ((0 == win->ray.dda.direction_dda && win->ray.direction_x > 0)
		|| (win->ray.dda.direction_dda && win->ray.direction_y < 0))
		win->wall.row = 64 - win->wall.row - 1;
}

static int	ft_find_pixel(t_win *win, int x, int y)
{
	int	*wall;

	if (win->ray.dda.direction_dda)
	{
		if (win->ray.direction_y >= 0)
			wall = (int *)win->so.addr;
		else
			wall = (int *)win->no.addr;
	}
	else
	{
		if (win->ray.direction_x >= 0)
			wall = (int *)win->ea.addr;
		else
			wall = (int *)win->we.addr;
	}
	// if (win->ray.number == 0 || win->ray.number == 1 \
	// 	|| win->ray.number == 10 || win->ray.number == 40 \
	// 	|| win->ray.number == 100 || win->ray.number == 400 \
	// 	|| win->ray.number == 1000 || win->ray.number == 600)
	// {
	// 	ft_putstr_fd("---------------------------------------\n", 1);
	// 	ft_putstr_fd("number = ", 1);
	// 	ft_putnbr(win->ray.number, 1);
	// 	ft_putendl_fd("", 1);
	// 	printf("distance wall: %f\n", win->wall.distance);
	// 	ft_putendl_fd("", 1);
	// 	printf("height wall: %d\n", win->wall.height);
	// 	ft_putendl_fd("", 1);
	// 	printf("start pixel wall: %d\n", win->wall.start_pixel);
	// 	ft_putendl_fd("", 1);
	// 	ft_putstr_fd("x wall: ", 1);
	// 	ft_putnbr(win->wall.x, 1);
	// 	ft_putendl_fd("", 1);
	// 	ft_putstr_fd("y wall: %f\n", win->wall.y);
	// 	ft_putendl_fd("", 1);
	// 	ft_putendl_fd("---------------------------------------", 1);
	// }
	return (wall[64 * y + x]);
}

void	ft_draw_wall(t_win *win)
{
	double	interpolation;
	int		color;
	int		i;

	i = 0;
	win->wall.column = 0;
	interpolation = (double)64 / (double)win->wall.height;
	while (i < win->wall.height)
	{
		color = ft_find_pixel(win, win->wall.row, \
			(int)win->wall.column);
		ft_put_pixel(win, win->ray.number, win->wall.start_pixel + i, color);
		win->wall.column += interpolation;
		++i;
	}
	// ft_putnbr_fd(color, 1);
}
