/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:17:59 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/19 12:48:06 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define SPEED 0.1
#define ROT_SPEED 0.05

void	move_up_down(t_win *win, int keycode)
{
	if (keycode == UP)
	{
		// printf("player pos y:%f x:%f\n", \
		// 	win->player.position_y, win->player.position_x);
		// if coordinates > 8.1 and < 8.9
		if (win->map[(int)(win->player.position_y + win->player.direction_y \
			* SPEED)][(int)win->player.position_x] != '1')
			win->player.position_y += win->player.direction_y * SPEED;
		if (win->map[(int)win->player.position_y][(int)(win->player.position_x \
			+ win->player.direction_x * SPEED)] != '1')
			win->player.position_x += win->player.direction_x * SPEED;
	}
	else if (keycode == DOWN)
	{
		// printf("player pos y:%f x:%f\n", \
		// 	win->player.position_y, win->player.position_x);
		if (win->map[(int)(win->player.position_y - win->player.direction_y \
			* SPEED)][(int)win->player.position_x] != '1')
			win->player.position_y -= win->player.direction_y * SPEED;
		if (win->map[(int)win->player.position_y][(int)(win->player.position_x \
			- win->player.direction_x * SPEED)] != '1')
			win->player.position_x -= win->player.direction_x * SPEED;
	}
	ft_putendl_fd("[Log] move_up_down", 2);
}

void	move_left_right(t_win *win, int keycode)
{
	if (keycode == RIGHT)
	{
		if (win->map[(int)(win->player.position_y + win->ray.plane_y \
			* SPEED)][(int)win->player.position_x] != '1')
			win->player.position_y += win->ray.plane_y * SPEED;
		if (win->map[(int)win->player.position_y][(int)(win->player.position_x \
			+ win->ray.plane_x * SPEED)] != '1')
			win->player.position_x += win->ray.plane_x * SPEED;
	}
	else if (keycode == LEFT)
	{
		if (win->map[(int)(win->player.position_y - win->ray.plane_y \
			* SPEED)][(int)win->player.position_x] != '1')
			win->player.position_y -= win->ray.plane_y * SPEED;
		if (win->map[(int)win->player.position_y][(int)(win->player.position_x \
			- win->ray.plane_x * SPEED)] != '1')
			win->player.position_x -= win->ray.plane_x * SPEED;
	}
	ft_putendl_fd("[Log] move_left_right", 2);
}

void	rotate_left(t_win *win)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = win->player.direction_x;
	win->player.direction_x = win->player.direction_x * cos(-ROT_SPEED) - \
	win->player.direction_y * sin(-ROT_SPEED);
	win->player.direction_y = old_dir_x * sin(-ROT_SPEED) + \
	win->player.direction_y * cos(-ROT_SPEED);
	old_plane_x = win->ray.plane_x;
	win->ray.plane_x = win->ray.plane_x * cos(-ROT_SPEED) - \
	win->ray.plane_y * sin(-ROT_SPEED);
	win->ray.plane_y = old_plane_x * sin(-ROT_SPEED) + \
	win->ray.plane_y * cos(-ROT_SPEED);
}

void	rotate_right(t_win *win)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = win->player.direction_x;
	win->player.direction_x = win->player.direction_x * cos(ROT_SPEED) - \
	win->player.direction_y * sin(ROT_SPEED);
	win->player.direction_y = old_dir_x * sin(ROT_SPEED) + \
	win->player.direction_y * cos(ROT_SPEED);
	old_plane_x = win->ray.plane_x;
	win->ray.plane_x = win->ray.plane_x * cos(ROT_SPEED) - \
	win->ray.plane_y * sin(ROT_SPEED);
	win->ray.plane_y = old_plane_x * sin(ROT_SPEED) + \
	win->ray.plane_y * cos(ROT_SPEED);
}
