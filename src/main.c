/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:04:03 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/15 13:20:56 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_win(t_win *win, int argc, char **argv)
{
	win->mlx = mlx_init();
	if (!win->mlx)
		error("MLX Error", 0);
	ft_init_img(win);
	parse_map(argc, argv, win);
	ft_init_mlx(win);
}

int	main(int argc, char **argv)
{
	t_win	win;

	if (argc != 2)
		return (0);
	init_win(&win, argc, argv);
	ft_render(&win);
	mlx_loop(win.mlx);
}
