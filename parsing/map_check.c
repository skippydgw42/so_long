/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:19:23 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/04 15:16:17 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_rect_map(char **map)
{
	int		i;
	size_t	size;

	i = 1;
	size = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != size)
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int	is_map_closed(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[0][j] != '1' || map[i][0] != '1')
				return (0);
			if (map[i][ft_strlen(map[i]) - 1] != '1')
				return (0);
			if (!map[i + 1] && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_char(char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E' && c != 'X')
		return (0);
	return (1);
}

int	map_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!valid_char(map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}