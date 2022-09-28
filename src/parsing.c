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
	return (ft_strncmp(&s[i], extension, 4));
}

void	print_list(void *content)
{
	printf("%s", (char *)content);
}

t_list	*get_map(int fd)
{
	char	*line;
	t_list	*map;

	map = NULL;
	while (1)
	{
		line = get_next_line_new(fd);
		if (!line)
			break ;
		ft_lstadd_back(&map, ft_lstnew(line));
	}
	ft_lstiter(map, print_list);
	return (map);
}

void	parse_map(int argc, char **argv, t_win *win)
{
	int	fd;

	(void)win;
	if (argc == 1 || wrong_extension(argv[1], ".cub"))
		error ("Wrong arguments", 0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("Can't open the map", 1);
	get_map(fd);
	close(fd);
}
