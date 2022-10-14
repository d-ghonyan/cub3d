/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:47:29 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/14 19:14:41 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*render(t_win *win)
{
	drow_floor_and_ceil(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	return (0);
}
