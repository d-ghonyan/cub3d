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
	int		j;
	int		w;
	int		h;
	
	int		color;
	char	*dst;

	i = -1;
	void	*img = mlx_xpm_file_to_image(win->mlx, "./minimap/pixel.xpm", &w, &h);
	if (!img)
		error("a", 1);
	while (++i < win->map_len)
	{
		j = -1;
		while (++j < ft_strlen(win->map[i]))
		{
			// color = 123 << 16 | 0 << 8 | 255;
			if (win->map[i][j] == '1')
				mlx_put_image_to_window(win->mlx, win->win, img, j * w, i * h);
			// else if (win->map[i / SIDE][j / SIDE] == ' ')
			// 	color = 255 << 24 | 0;
			// else if (i / SIDE == win->player.pos_y_mini
			// 	&& j / SIDE == win->player.pos_x_mini)
			// {
			// 	printf("PLAYER\n");
			// 	color = 255 << 8 | 0;
			// }
			// dst = win->addr_mini + (i * win->line_length_mini
			// 		+ j * (win->bits_per_pixel_mini / 8));
			// *(unsigned int *)(dst) = color;
		}
	}
	// mlx_put_image_to_window(win->mlx, win->win, win->img_mini, 0, 0);
}
