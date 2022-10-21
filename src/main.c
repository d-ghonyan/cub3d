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
	parse_map(argc, argv, win);
	ft_init_img(win);
	ft_init_mlx(win);
}

void	draw_minimap(t_win *win)
{
	int		i;
	int		j;
	char	*dst;
	i = -1;
	while (++i < win->map_len * SIDE)
	{
		j = -1;
		while (++j < ft_strlen(win->map[i / SIDE]) * SIDE)
		{
			int color = 123 << 16 | 0 << 8 | 255;
			if (win->map[i / SIDE][j / SIDE] == '0')
				color = 255 << 24 | 23 << 16 | 0 << 8 | 9;
			else if (win->map[i / SIDE][j / SIDE] == ' ')
				color = 255 << 24 | 0;
			dst = win->addr_mini + (i * win->line_length_mini
					+ j * (win->bits_per_pixel_mini / 8));
			*(unsigned int *)(dst) = color;
		}
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img_mini, 0, 0);
}

int	main(int argc, char **argv)
{
	t_win	win;

	if (argc != 2)
		return (0);
	init_win(&win, argc, argv);
	draw_minimap(&win);
	// ft_render(&win);
	// ft_putendl_fd("[Log] first render", 2);
	mlx_loop(win.mlx);
}
