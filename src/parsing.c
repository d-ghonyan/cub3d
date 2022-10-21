/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:18:56 by dghonyan          #+#    #+#             */
/*   Updated: 2022/10/15 10:29:38 by mtiesha          ###   ########.fr       */
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

int	valid(char c, int check_surrounded)
{
	if (check_surrounded)
		return (c == '1' || c == 'N' || c == 'W'
			|| c == 'E' || c == 'S' || c == '0');
	return (c == '\n' || c == '1' || c == '0' || c == 'N'
		|| c == 'W' || c == 'E' || c == 'S' || c == ' ' || c == '\t');
}

void	parse_map(int argc, char **argv, t_win *win)
{
	int		fd;
	char	**map;
	char	**saved_map;

	if (wrong_extension(argv[1], ".cub"))
		error ("Wrong arguments", 0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("Can't open the map", 1);
	map = get_map(fd);
	saved_map = map;
	if (get_options(&map, win) || !map)
		error("Missing options", 0);
	map = convert_tabs(map, saved_map);
	validate_map(win, map);
	win->map = map;
	close(fd);
}
