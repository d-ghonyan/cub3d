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

/* so many things to change */

#include "cub3d.h"

int	have_newlines(t_list *map)
{
	t_list	*temp;

	temp = map;
	while (temp && ft_strcmp(temp->content, "\n"))
		temp = temp->next;
	while (temp && !ft_strcmp(temp->content, "\n"))
		temp = temp->next;
	return (temp != NULL);
}

int	valid_map_char(char c)
{
	return (c == '\n' || c == '1' || c == '0' || c == 'N'
		|| c == 'W' || c == 'E' || c == 'S');
}

int	whatever(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (!s[i])
		return (1);
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		while (s[i] && s[i] != ' ')
		{
			if (!valid_map_char(s[i]))
				return (1);
			i++;
		}
	}
	return (0);
}

int	check_walls_end(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		while (line[i] == ' ')
			i++;
		while (line[i] != ' ')
		{
			if (line[i] != '1')
				return (1);
			i++;
		}
	}
	return (0);
}

int	check_walls_mid(char *line)
{
	int	i;
	int	iter;

	i = 0;
	iter = 0;
	while (line[i] && line[i] != '\n')
	{
		while (line[i] == ' ')
			i++;
		while (line[i] != ' ')
		{
			if (line[i] != '1')
				return (1);
			i++;
		}
		iter++;
	}
	return (0);
}

int	is_surrounded(t_list *map)
{
	int	i;
	int	j;

	i = 0;
	while (map)
	{
		j = 0;
		if (i == 0 || !map->next)
			check_walls_end(map->content);
		else
		{
		}
	}
}

int	wrong_map(t_list *map)
{
	t_list	*temp;

	temp = map;
	while (temp)
	{
		if (whatever(temp->content))
			return (1);
		temp = temp->next;
	}
	return (have_newlines(map));
}
