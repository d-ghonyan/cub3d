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

int	wrong_extension(char *s, char *extension)
{
	int	i;

	if (ft_strlen(s) < 4)
		return (1);
	i = ft_strlen(s) - 4;
	return (ft_strncmp(&s[i], extension, ft_strlen(extension)));
}

int	is_in_check(char *s, char *check[6])
{
	int	j;

	j = 0;
	while (check[j])
	{
		if (!ft_strcmp(s, check[j]))
			return (1);
		j++;
	}
	return (0);
}

int	init_check(char *(*check)[7], t_list *map)
{
	int	i;

	i = 0;
	while (i < 7)
		(*check)[i++] = NULL;
	return (!map);
}

void	free_map(t_list **map)
{
	t_list	*temp;

	while ((*map) && !ft_strcmp((*map)->content, "\n"))
	{
		temp = *map;
		*map = (*map)->next;
		free(temp);
	}
}

int	hello(t_list **map, t_win *win)
{
	int		i;
	t_list	*temp;
	char	**line;
	char	*check[7];

	i = 0;
	free_map(map);
	if (init_check(&check, *map))
		return (1);
	while (*map && i != 6)
	{
		line = ft_split((*map)->content, ' ');
		if (!is_allowed(line[0]) || !line[1])
			error("Wrong options", 0);
		if (i && is_in_check(line[0], check))
			error("Duplicates", 0);
		check[i++] = ft_strdup(line[0]);
		temp = *map;
		*map = (*map)->next;
		free(temp);
		free_map(map);
		ft_splfree(line);
	}
	return (i != 6);
}

t_list	*get_map(int fd)
{
	char	*line;
	t_list	*map;

	map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_lstadd_back(&map, ft_lstnew(line));
	}
	return (map);
}

void	parse_map(int argc, char **argv, t_win *win)
{
	int		fd;
	t_list	*map;

	(void)win;
	if (argc == 1 || wrong_extension(argv[1], ".cub"))
		error ("Wrong arguments", 0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("Can't open the map", 1);
	map = get_map(fd);
	if (hello(&map, win) || !map)
		error("Missing options", 0);
	if (wrong_map(map))
		error("Wrong map", 0);
	while (map)
	{
		printf("%s\n", map->content);
		map = map->next;
	}
	close(fd);
}
