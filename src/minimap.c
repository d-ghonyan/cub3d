/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:18:56 by dghonyan          #+#    #+#             */
/*   Updated: 2022/10/20 19:47:57 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	int		i;
	int		map_len = have_newlines(win->map);
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    int		x;
    int		y;
	int		j;
	char	*dst;
	int		side = 12;
	void	*img = mlx_new_image(win->mlx, max_len(win->map) * side, map_len * side);
	char	*addr = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);
	i = -1;
	while (++i < map_len * side)
	{
		j = -1;
		while (++j < ft_strlen(win->map[i / side]) * side)
		{
			int color = 123 << 16 | 0 << 8 | 255;
			if (win->map[i / side][j / side] == '0')
				color = 255 << 24 | 23 << 16 | 0 << 8 | 9;
			else if (win->map[i / side][j / side] == ' ')
				color = 255 << 24 | 0;
			else if (i / side == win->player.map_position_y && j / side == win->player.map_position_x)
				color = 255 << 16 | 255 << 8 | 9;
			dst = addr + (i * line_length
					+ j * (bits_per_pixel / 8));
			*(unsigned int *)(dst) = color;
		}
	}
	mlx_put_image_to_window(win->mlx, win->win, img, 20, 20);
}
