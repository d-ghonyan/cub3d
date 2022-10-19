/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:01:40 by dghonyan          #+#    #+#             */
/*   Updated: 2022/10/19 17:59:05 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_win *win)
{
	if (keycode == ESC)
		destroy_hook(win);
	else if (keycode == UP || keycode == DOWN)
		move_up_down(win, keycode);
	else if (keycode == LEFT || keycode == RIGHT)
		move_left_right(win, keycode);
	else if (keycode == ROTATE_LEFT)
		rotate_left(win);
	else if (keycode == ROTATE_RIGHT)
		rotate_right(win);
	else if (keycode == M_KEY)
		win->flag_map = 1 - win->flag_map - 0;
	else if (keycode == N_KEY)
		win->flag_mouse = 1 - win->flag_mouse - 0;
	ft_putendl_fd("[Log] re render", 2);
	ft_render(win);
	return (0);
}

int	mouse_hook(int code, int x, int y, t_win *win)
{
	ft_putstr_fd("[Log] mouse_hook: ", 2);
	ft_putnbr_fd(x, 2);
	ft_putchar_fd('\n', 2);
	(void)code;
	(void)y;
	(void)win;
	return (0);
}

int	destroy_hook(t_win *win)
{
	(void)win;
	exit(EXIT_SUCCESS);
}
