/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:06:24 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/14 19:11:53 by mtiesha          ###   ########.fr       */
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
#  define WIDTH_WIN 1024
#  define HEIGHT_WIN 800
# else
#  include <mlx.h>

#  define ESC 53
#  define UP_A 126
#  define DOWN_A 125
#  define LEFT_A 123
#  define RIGHT_A 124
#  define WIDTH_WIN 2560
#  define HEIGHT_WIN 1400

# endif

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_img
{
	int		w;
	int		h;
	int		fd;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img;
}	t_img;

typedef struct s_window
{
	t_img	no;
	t_img	ea;
	t_img	we;
	t_img	so;
	int		f_color;
	int		c_color;
	char	**map;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
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
int		wrong_map(t_list *map);
int		wrong_extension(char *s, char *extension);
char	**get_map(int fd);
int		get_options(char ***map, t_win *win);
void	file_error(char *s);
int		validate_map(char **map);
int		space_or_nl(char *s);
int		valid(char c, int check_surrounded);
int		ft_strlen_map(char *s);
char	**convert_tabs(char **map, char **saved);

void	drow_floor_and_ceil(t_win *win);

int		*render(t_win *win);

#endif
