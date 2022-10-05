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

int	check_characters(char **map, int len)
{
	int	i;
	int	j;
	int	player;

	i = -1;
	player = 0;
	while (++i < len)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'W' || map[i][j] == 'E'
				|| map[i][j] == 'N' || map[i][j] == 'S')
				player++;
			if (!valid_map_char(map[i][j], 0))
				return (0);
		}
	}
	return (player == 1);
}

int	have_newlines(char **map)
{
	int	i;
	int	nl_index;

	i = 0;
	nl_index = 0;
	while (map[i] && !space_or_nl(map[i]))
		i++;
	nl_index = i;
	while (map[nl_index] && space_or_nl(map[nl_index]))
		nl_index++;
	if (!map[nl_index])
		return (i);
	return (-1);
}

int	first_last(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i++;
		while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		{
			if (s[i] != '1')
				return (0);
			i++;
		}
	}
	return (1);
}

int	middle(char *s, char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i++;
		while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		{
			if ((s[i] == '0') && (!valid_map_char(s1[i], 1)
					|| !valid_map_char(s2[i], 1)
					|| !valid_map_char(s[i - 1], 1)
					|| !valid_map_char(s[i + 1], 1)
					|| !valid_map_char(s1[i - 1], 1)
					|| !valid_map_char(s1[i + 1], 1)
					|| !valid_map_char(s2[i - 1], 1)
					|| !valid_map_char(s2[i + 1], 1)))
				return (0);
			i++;
		}
	}
	return (1);
}

int	validate_map(char **map)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	len = have_newlines(map);
	if (len < 0)
		return (0);
	if (!check_characters(map, len))
		error("Something's wrong with characters...", 0);
	while (++i < len)
	{
		j = -1;
		if ((i == 0 || i == len - 1) && !first_last(map[i]))
			error("Map not surrunded by walls", 0);
		else if (i > 0 && i < len - 1
			&& !middle(map[i], map[i - 1], map[i + 1]))
			error("Map not surrunded by walls", 0);
	}
	return (0);
}