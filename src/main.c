/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:04:03 by mtiesha           #+#    #+#             */
/*   Updated: 2022/09/11 13:43:42 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init(t_win *s)
{
	(*s).mlx = mlx_init();
	if (NULL == (*s).mlx)
		ft_putendl_fd("MLX Error", 2);
	(*s).mlx_win = mlx_new_window((*s).mlx, WH, WH, "CUB3D");
	if (NULL == (*s).mlx_win)
	{
		free(s->mlx_win);
		ft_putendl_fd("Window Error", 2);
	}
	(*s).img = mlx_new_image((*s).mlx, WH, WH);
	if (!(*s).img)
		ft_putendl_fd("IMG Error", 2);
	(*s).addr = mlx_get_data_addr((*s).img, \
			&(*s).bits_per_pixel, &(*s).line_length, \
			&(*s).endian);
	if (!(*s).img)
		ft_putendl_fd("IMG Fill(bpp etc) Error", 2);
}

int	main(void)
{
	t_win	img;

	ft_init(&img);
	mlx_loop(img.mlx);
	mlx_destroy_window(img.mlx, img.mlx_win);
	free(img.mlx);
}