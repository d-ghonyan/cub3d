/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:04:03 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/15 17:50:39 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_win(t_win *win, int argc, char **argv)
{
	ft_init_img(win);
	ft_init_mlx(win);
	parse_map(argc, argv, win);
}

int	main(int argc, char **argv)
{
	t_win	win;

	init_win(&win, argc, argv);
	ft_render(&win);
	mlx_hook(win.win, 2, 1L << 0, key_hook, &win);
	ft_putendl_fd("[Log] first render", 2);
	mlx_loop(win.mlx);
}
