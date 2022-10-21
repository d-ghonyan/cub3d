/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:17:59 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/20 20:08:36 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_up(t_win *win, int keycode)
{
	if (keycode == UP)
	{
		if (win->map[(int)(win->player.position_y + win->player.direction_y \
			* (SPEED_D))][(int)win->player.position_x] != '1')
		{
			win->player.pos_y_mini += SPEED;
			win->player.position_y += win->player.direction_y * SPEED;
		}
		if (win->map[(int)win->player.position_y][(int)(win->player.position_x \
			+ win->player.direction_x * SPEED_D)] != '1')
		{
			win->player.pos_x_mini += SPEED;
			win->player.position_x += win->player.direction_x * SPEED;
		}
	}
}

void	key_right(t_win *win, int keycode)
{
	if (keycode == RIGHT)
	{
		if (win->map[(int)(win->player.position_y + win->ray.plane_y \
			* SPEED_D)][(int)win->player.position_x] != '1')
		{
			win->player.pos_x_mini += SPEED;
			win->player.position_y += win->ray.plane_y * SPEED;
		}
		if (win->map[(int)win->player.position_y][(int)(win->player.position_x \
			+ win->ray.plane_x * SPEED_D)] != '1')
		{
			win->player.pos_x_mini += SPEED;
			win->player.position_x += win->ray.plane_x * SPEED;
		}
	}
}
