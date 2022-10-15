/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:16:50 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/15 13:46:19 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_dda_ray(t_win *win)
{
	win->ray.direction_x = 0;
	win->ray.direction_y = 0;
	win->ray.plane_x = 0.0;
	win->ray.plane_y = 0.0;
	win->ray.number = 0;
	win->ray.dda.direction_dda = 0;
	win->ray.dda.cell_distance_x = 0;
	win->ray.dda.cell_distance_y = 0;
	win->ray.dda.step_x = 0;
	win->ray.dda.step_y = 0;
	win->ray.dda.shift_x = 0;
	win->ray.dda.shift_y = 0;
}

static void	ft_init_wall_player(t_win *win)
{
	win->wall.row = 0.0;
	win->wall.column = 0.0;
	win->wall.height = 0;
	win->wall.start_pixel = 0;
	win->wall.distance = 0.0;
	win->player.map_position_x = 0;
	win->player.map_position_y = 0;
	win->player.position_x = 0.0;
	win->player.position_y = 0.0;
	win->player.direction_x = 0.0;
	win->player.direction_y = 0.0;
}

void	ft_init_img(t_win *win)
{
	win->ea.fd = -1;
	win->we.fd = -1;
	win->so.fd = -1;
	win->no.fd = -1;
	win->no.img = NULL;
	win->no.bits_per_pixel = 0;
	win->no.line_length = 0;
	win->no.endian = 0;
	win->we.img = NULL;
	win->we.bits_per_pixel = 0;
	win->we.line_length = 0;
	win->we.endian = 0;
	win->ea.img = NULL;
	win->ea.bits_per_pixel = 0;
	win->ea.line_length = 0;
	win->ea.endian = 0;
	win->so.img = NULL;
	win->so.bits_per_pixel = 0;
	win->so.line_length = 0;
	win->so.endian = 0;
	ft_init_wall_player(win);
	ft_init_dda_ray(win);
}

static void	mlx_hooks(t_win *win)
{
	mlx_key_hook(win->win, &key_hook, win);
	mlx_mouse_hook(win->win, &mouse_hook, win);
	mlx_hook(win->win, 17, 0, &destroy_hook, win);
}

void	ft_init_mlx(t_win *win)
{
	win->map = NULL;
	win->mlx = NULL;
	win->win = NULL;
	win->img = NULL;
	win->addr = NULL;
	win->mlx = mlx_init();
	if (!win->mlx)
		error("MLX Error", 0);
	win->win = mlx_new_window(win->mlx, WIDTH_WIN, HEIGHT_WIN, "CUB3D");
	if (NULL == win->win)
		error("Window Error", 0);
	win->img = mlx_new_image(win->mlx, WIDTH_WIN, HEIGHT_WIN);
	if (!win->img)
		error("IMG Error", 0);
	win->addr = mlx_get_data_addr(win->img,
			&win->bits_per_pixel, &win->line_length,
			&win->endian);
	if (!win->addr)
		error("IMG Fill(bpp etc) Error", 0);
	mlx_hooks(win);
}
