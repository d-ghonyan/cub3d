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

int	is_surrounded(char *s)
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

int	valid_chars(t_list *map)
{
	int		i;
	char	*line;

	while (map)
	{
		i = 0;
		line = map->content;
		while (line[i] == ' ')
			i++;
		if (line[i] != '1')
			return (0);
	}
}

int	wrong_map(t_list *map)
{
	t_list	*temp;

	temp = map;
	while (temp)
	{
		if (is_surrounded(temp->content))
			return (1);
		temp = temp->next;
	}
	return (have_newlines(map));
}
