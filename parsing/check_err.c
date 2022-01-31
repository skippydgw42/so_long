/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:08:11 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/01/31 15:35:52 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_items_count(t_items items)
{
	if (items.exit <= 0 || items.collec <= 0)
		return (0);
	if (items.player != 1)
		return (0);
	return (1);
}

int	check_items(char **map, t_items items)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				items.player += 1;
			if (map[i][j] == 'E')
				items.exit += 1;
			if (map[i][j] == 'C')
				items.collec += 1;
			j++;
		}
		i++;
	}
	if (!check_items_count(items))
		return (0);
	return (1);
}

t_items	check_err(char **map)
{
	t_items	items;

	items.collec = 0;
	items.exit = 0;
	items.player = 0;
	items.valid = 0;
	if (!map_check(map) || !is_rect_map(map) || !is_map_closed(map))
		return (items);
	if (!check_items(map, items))
		return (items);
	items.valid = 1;
	return (items);
}