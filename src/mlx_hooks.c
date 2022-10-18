/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:01:40 by dghonyan          #+#    #+#             */
/*   Updated: 2022/10/18 12:48:51 by mtiesha          ###   ########.fr       */
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
	// ft_putstr_fd("[Log] key_hook: ", 2);
	// ft_putnbr_fd(keycode, 2);
	// ft_putchar_fd('\n', 2);
	ft_render(win);
	// ft_putendl_fd("[Log] re render", 2);
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
