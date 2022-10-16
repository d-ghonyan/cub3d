/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:01:40 by dghonyan          #+#    #+#             */
/*   Updated: 2022/10/16 10:51:05 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_win *win)
{
	if (keycode == ESC)
		destroy_hook(win);
	else if (keycode == UP)
		move_up(win);
	else if (keycode == DOWN)
		move_down(win);
	else if (keycode == LEFT)
		move_left(win);
	else if (keycode == RIGHT)
		move_right(win);
	else if (keycode == ROTATE_LEFT)
		rotate_left(win);
	else if (keycode == ROTATE_RIGHT)
		rotate_right(win);
	ft_render(win);
	ft_putendl_fd("[Log] re render", 2);
	return (0);
}

int	mouse_hook(int code, int x, int y, t_win *win)
{
	(void)code;
	(void)x;
	(void)y;
	(void)win;
	return (0);
}

int	destroy_hook(t_win *win)
{
	(void)win;
	exit(EXIT_SUCCESS);
}
