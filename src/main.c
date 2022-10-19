/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:04:03 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/19 18:09:43 by mtiesha          ###   ########.fr       */
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
	ft_putendl_fd("[Log] first render", 2);
	mlx_loop(win.mlx);
}
