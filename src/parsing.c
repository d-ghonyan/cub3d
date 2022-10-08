/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <dghonyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:18:56 by dghonyan          #+#    #+#             */
/*   Updated: 2022/09/25 17:34:21 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" 

int	valid_map_char(char c, int check_surrounded)
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

	(void)win;
	if (argc == 1 || wrong_extension(argv[1], ".cub"))
		error ("Wrong arguments", 0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("Can't open the map", 1);
	map = get_map(fd);
	saved_map = map;
	if (get_options(&map, win) || !map)
		error("Missing options", 0);
	map = convert_tabs(map, saved_map);
	validate_map(map);
	int i = -1;
	while (map[++i])
		printf("%s", map[i]);
	close(fd);
}
