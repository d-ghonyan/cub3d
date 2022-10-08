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

int	space_or_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen_map(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '\t')
			len += 4;
		else
			len++;
		i++;
	}
	return (len);
}

char	*convert(char *s)
{
	int		i;
	int		j;
	int		k;
	char	*res;

	i = (j = 0);
	res = malloc(sizeof (*res) * (ft_strlen_map(s) + 1));
	if (!res)
		error("malloc", 1);
	while (s[i])
	{
		k = -1;
		if (s[i] == '\t')
		{
			while (++k < 4)
				res[j++] = ' ';
			i++;
		}
		else
			res[j++] = s[i++];
	}
	res[j] = '\0';
	return (res);
}

char	**convert_tabs(char **map, char **saved)
{
	int		i;
	char	**res;

	i = -1;
	res = malloc(sizeof (*res) * (ft_spllen(map) + 1));
	if (!res)
		error("malloc", 1);
	while (map[++i])
		res[i] = convert(map[i]);
	res[i] = NULL;
	i = -1;
	while (map[++i])
		free(map[i]);
	free(saved);
	return (res);
}
