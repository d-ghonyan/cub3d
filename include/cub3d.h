/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <dghonyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:06:24 by mtiesha           #+#    #+#             */
/*   Updated: 2022/09/25 17:25:33 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifdef LINUX
#  include "mlx.h"

#  define ESC 65307
#  define UP 119
#  define DOWN 115
#  define LEFT 97
#  define RIGHT 100
# else
#  include <mlx.h>

#  define ESC 53
#  define UP_A 126
#  define DOWN_A 125
#  define LEFT_A 123
#  define RIGHT_A 124
# endif

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define WH 800

typedef struct s_window
{
	t_list	*map;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	void	*no_img;
	void	*we_img;
	void	*ea_img;
	void	*so_img;
	int		no_fd;
	int		we_fd;
	int		ea_fd;
	int		so_fd;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_win;

/* my pixel_put, from 42docs */
void	ft_put_pixel(t_win *img, int x, int y, int color);
/* atoi for double: convert char 3.14 to double 3.14, _f like float */
double	ft_atoi_f(const char *str);
/* check str before atoi_f */
int		ft_vld_f(char *str);

int		key_hook(int keycode, t_win *win);
int		destroy_hook(t_win *win);
int		mouse_hook(int code, int x, int y, t_win *win);
void	parse_map(int argc, char **argv, t_win *img);

/* perror if syscall is true, putendl_fd if false and exit */
void	error(char *msg, int syscall);

#endif
