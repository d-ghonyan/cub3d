/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <dghonyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:04:03 by mtiesha           #+#    #+#             */
/*   Updated: 2022/09/25 17:25:21 by dghonyan         ###   ########.fr       */
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
	if (NULL == s->mlx)
		error("MLX Error", 0);
	s->win = mlx_new_window(s->mlx, WH, WH, "CUB3D");
	if (NULL == s->win)
		error("Window Error", 0);
	s->img = mlx_new_image(s->mlx, WH, WH);
	if (!s->img)
		error("IMG Error", 0);
	s->addr = mlx_get_data_addr(s->img,
			&s->bits_per_pixel, &s->line_length,
			&s->endian);
	if (!s->addr)
		error("IMG Fill(bpp etc) Error", 0);
	mlx_hooks(s);
}

void	init_win(t_win *win)
{
	win->ea_fd = -1;
	win->we_fd = -1;
	win->so_fd = -1;
	win->no_fd = -1;
	win->map = NULL;
	win->mlx = NULL;
	win->win = NULL;
	win->img = NULL;
	win->addr = NULL;
	win->no_img = NULL;
	win->we_img = NULL;
	win->ea_img = NULL;
	win->so_img = NULL;
	win->no_file = NULL;
	win->we_file = NULL;
	win->ea_file = NULL;
	win->so_file = NULL;
	win->f_color = NULL;
	win->c_color = NULL;
}

int	main(int argc, char **argv)
{
	t_win	img;

	init_win(&img);
	parse_map(argc, argv, &img);
}
	// ft_init(&img);
	// mlx_loop(img.mlx);
