/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:06:24 by mtiesha           #+#    #+#             */
/*   Updated: 2022/10/20 19:11:21 by mtiesha          ###   ########.fr       */
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
#  define ROTATE_LEFT 65361
#  define ROTATE_RIGHT 65363
#  define WIDTH_WIN 1024
#  define HEIGHT_WIN 800
#  define M_KEY 109
#  define N_KEY 108

# else
#  include <mlx.h>

#  define ESC 53
#  define UP 13
#  define DOWN 1
#  define LEFT 0
#  define RIGHT 2
#  define ROTATE_LEFT 123
#  define ROTATE_RIGHT 124
#  define WIDTH_WIN 1500
#  define HEIGHT_WIN 1000
#  define M_KEY 46
#  define N_KEY 45

# endif

# define SIDE 12
# define SPEED 0.1
# define SPEED_D 0.3
# define ROT_SPEED 0.05

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

typedef struct s_player
{
	int		map_position_x;
	int		map_position_y;
	double	position_x;
	double	position_y;
	double	direction_x;
	double	direction_y;
	int		pos_x_mini;
	int		pos_y_mini;
}	t_player;

typedef struct s_dda
{
	int		direction_dda;
	double	cell_distance_x;
	double	cell_distance_y;
	int		step_x;
	int		step_y;
	double	shift_x;
	double	shift_y;
}	t_dda;

typedef struct s_ray
{
	double	direction_x;
	double	direction_y;
	double	plane_x;
	double	plane_y;
	int		number;
	int		door;
	t_dda	dda;
}	t_ray;

typedef struct s_wall
{
	double	row;
	double	column;
	int		height;
	int		start_pixel;
	double	distance;
}	t_wall;

typedef struct s_window
{
	t_img		no;
	t_img		ea;
	t_img		we;
	t_img		so;
	t_img		door;
	int			f_color;
	int			c_color;
	char		**map;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*img_mini;
	char		*addr_mini;
	int			map_len;
	int			bits_per_pixel_mini;
	int			line_length_mini;
	int			endian_mini;
	t_ray		ray;
	t_wall		wall;
	t_player	player;
	int			flag_mouse;
	int			past_mouse_pos_x;
	int			flag_map;
}	t_win;

/* my pixel_put, from 42docs */
void	ft_put_pixel(t_win *img, int x, int y, int color);
/* atoi for double: convert char 3.14 to double 3.14, _f like float */
double	ft_atoi_f(const char *str);
/* check str before atoi_f */
int		ft_vld_f(char *str);

int		key_hook(int keycode, t_win *win);
int		destroy_hook(t_win *win);
int		mouse_hook(int x, int y, t_win *win);
void	parse_map(int argc, char **argv, t_win *img);

/* perror if syscall is true, putendl_fd if false and exit */
void	error(char *msg, int syscall);
int		wrong_map(t_list *map);
int		wrong_extension(char *s, char *extension);
char	**get_map(int fd);
int		get_options(char ***map, t_win *win);
void	file_error(char *s);
int		validate_map(t_win *win, char **map);
int		space_or_nl(char *s);
int		valid(char c, int check_surrounded);
int		ft_strlen_map(char *s);
char	**convert_tabs(char **map, char **saved);

/*init struct.c*/
void	ft_init_img(t_win *win);
void	ft_init_mlx(t_win *s);
void	ft_set_player(t_win *win, char dir, int x, int y);//parsing_utils.c

void	draw_floor_and_ceil(t_win *win);

void	ft_calc_dist_height_wall(t_win *win);
void	ft_calc_row_wall(t_win *win);
void	ft_draw_wall(t_win *win);

/*manage_keys.c*/
void	move_up_down(t_win *win, int keycode);
void	move_left_right(t_win *win, int keycode);
void	key_up(t_win *win, int keycode);
void	key_right(t_win *win, int keycode);
void	rotate_left(t_win *win);
void	rotate_right(t_win *win);

int		*ft_render(t_win *win);

void	draw_minimap(t_win *win);
int		have_newlines(char **map);
int		max_len(char **map);
void	store_xpm(t_img *img, void *mlx, char *name);
void	init_player_dir(t_win *win, char dir, int x, int y);

/*doors.c*/
void	ft_enter_doors(t_win *win);
#endif
