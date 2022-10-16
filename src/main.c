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
	ft_init_img(win);
	ft_init_mlx(win);
	parse_map(argc, argv, win);
}

int	max_len(char **map)
{
	int	i;
	int	max;

	i = 0;
	max = ft_strlen(map[0]);
	while (map[++i])
	{
		if (max < ft_strlen(map[i]))
			max = ft_strlen(map[i]);
	}
	return (max);
}

void	draw_minimap(t_win *win)
{
	int	i;
	int	j;
	char	*dst;
	i = -1;
	int		side = 12;
	void	*img = mlx_new_image(win->mlx, max_len(win->map) * side, win->map_len * side);
	char	*addr = mlx_get_data_addr(img, &win->bits_per_pixel, &win->line_length, &win->endian);
	while (++i < win->map_len * side)
	{
		j = -1;
		while (++j < ft_strlen(win->map[i / side]) * side)
		{
			int color = 123 << 16 | 0 << 8 | 255;
			if (win->map[i / side][j / side] == '0')
				color = 23 << 16 | 0 << 8 | 9;
			else if (win->map[i / side][j / side] == ' ')
				color = 0;
			dst = addr + (i * win->line_length
					+ j * (win->bits_per_pixel / 8));
			*(unsigned int *)(dst) = color;
		}
	}
	mlx_put_image_to_window(win->mlx, win->win, img, 0, 0);
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
