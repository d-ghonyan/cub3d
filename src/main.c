/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:04:03 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/14 19:09:14 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_hooks(t_win *win)
{
	mlx_key_hook(win->win, &key_hook, win);
	mlx_mouse_hook(win->win, &mouse_hook, win);
	mlx_hook(win->win, 17, 0, &destroy_hook, win);
}

void	ft_init(t_win *s)
{
	s->mlx = mlx_init();
	if (!s->mlx)
		error("MLX Error", 0);
	s->win = mlx_new_window(s->mlx, WIDTH_WIN, HEIGHT_WIN, "CUB3D");
	if (NULL == s->win)
		error("Window Error", 0);
	s->img = mlx_new_image(s->mlx, WIDTH_WIN, HEIGHT_WIN);
	if (!s->img)
		error("IMG Error", 0);
	s->addr = mlx_get_data_addr(s->img,
			&s->bits_per_pixel, &s->line_length,
			&s->endian);
	if (!s->addr)
		error("IMG Fill(bpp etc) Error", 0);
	mlx_hooks(s);
}

void	init_win(t_win *win, int argc, char **argv)
{
	win->ea.fd = -1;
	win->we.fd = -1;
	win->so.fd = -1;
	win->no.fd = -1;
	win->map = NULL;
	win->mlx = NULL;
	win->win = NULL;
	win->img = NULL;
	win->addr = NULL;
	win->no.img = NULL;
	win->we.img = NULL;
	win->ea.img = NULL;
	win->so.img = NULL;
	ft_init(win);
	parse_map(argc, argv, win);
}

int	main(int argc, char **argv)
{
	t_win	win;

	if (argc != 2)
		return (0);
	init_win(&win, argc, argv);
	render(&win);
	mlx_loop(win.mlx);
}
