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

int	valid_map_char(char c)
{
	return (c == '\n' || c == '1' || c == '0' || c == 'N'
		|| c == 'W' || c == 'E' || c == 'S' || c == ' ' || c == '\t');
}

int	w_or_p(char c)
{
	return (c == '1' || c == 'N' || c == 'W'
		|| c == 'E' || c == 'S' || c == '0');
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
			if ((s[i] == '0')
				&& (!w_or_p(s1[i]) || !w_or_p(s2[i])
				|| !w_or_p(s[i - 1]) || !w_or_p(s[i + 1])))
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
	while (++i < len)
	{
		j = -1;
		if ((i == 0 || i == len - 1) && !first_last(map[i]))
			error("Map not surrunded by walls", 0);
		else if (i > 0 && i < len - 1 && !middle(map[i], map[i - 1], map[i + 1]))
			error("Map not surrunded by walls", 0);
	}
	return (1);
}
// if (!walls(map[i]))
// 	return (0);