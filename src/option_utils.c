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

void	init_check(char *(*check)[7])
{
	int	i;

	i = 0;
	while (i < 7)
		(*check)[i++] = NULL;
}

void	store_textures(t_win *win, char **line)
{
	if (!ft_strcmp(line[0], "NO"))
	{
		win->no_file = ft_strdup(line[1]);
		win->no_fd = open(line[1], O_RDONLY);
		if (!win->no_file || win->no_fd < 0)
		{
			file_error(line[1]);
		}
	}
	if (!ft_strcmp(line[0], "EA"))
	{
		win->ea_file = ft_strdup(line[1]);
		win->no_fd = open(line[1], O_RDONLY);
		if (!win->ea_file || win->ea_fd < 0)
			file_error(line[1]);
	}
	if (!ft_strcmp(line[0], "WE"))
	{
		win->we_file = ft_strdup(line[1]);
		win->no_fd = open(line[1], O_RDONLY);
		if (!win->we_file || win->we_fd < 0)
			file_error(line[1]);
	}
}

void	store_check(char **line, t_win *win)
{
	store_textures(win, line);
	if (!ft_strcmp(line[0], "SO"))
	{
		win->so_file = ft_strdup(line[1]);
		win->no_fd = open(line[1], O_RDONLY);
		if (!win->so_file || win->so_fd < 0)
			file_error(line[1]);
	}
	if (!ft_strcmp(line[0], "F"))
	{
		win->f_color = ft_strdup(line[1]);
		if (!win->f_color)
			file_error(line[1]);
	}
	if (!ft_strcmp(line[0], "C"))
	{
		win->c_color = ft_strdup(line[1]);
		if (!win->c_color)
			file_error(line[1]);
	}
}
