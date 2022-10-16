/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:17:59 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/16 16:53:17 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define SPEED 0.5
#define ROT_SPEED 0.05

void	move_up_down(t_win *win)
{
	ft_putendl_fd("move_up_down", 2);
}

void	move_left_right(t_win *win)
{
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
