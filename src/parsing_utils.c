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

int	is_allowed(char *s)
{
	return (!ft_strcmp(s, "NO") || !ft_strcmp(s, "WE")
		|| !ft_strcmp(s, "EA") || !ft_strcmp(s, "SO")
		|| !ft_strcmp(s, "F") || !ft_strcmp(s, "C"));
}
