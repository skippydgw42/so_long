/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:08:11 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/04 15:15:22 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_items_count(t_items *items)
{
	if (items->exit <= 0 || items->collec <= 0)
		return (0);
	if (items->player != 1)
		return (0);
	return (1);
}

int	check_items(char **map, t_items *items)
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
				items->player += 1;
			if (map[i][j] == 'E')
				items->exit += 1;
			if (map[i][j] == 'C')
				items->collec += 1;
			if (map[i][j] == 'X')
				items->ennemies += 1;
			j++;
		}
		i++;
	}
	if (!check_items_count(items))
		return (0);
	return (1);
}

void	check_err(t_data *data)
{
	data->items->collec = 0;
	data->items->exit = 0;
	data->items->player = 0;
	data->items->valid = 0;
	if (map_check(data->map) && is_rect_map(data->map) && is_map_closed(data->map))
		if (check_items(data->map, data->items))
			data->items->valid = 1;
}