/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:00:23 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/02 16:18:14 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// if (data->map[data->player->y][data->player->x] != 'E')

void	move_up(t_data *data)
{
	if (data->map[data->player->y - 1][data->player->x] != '1')
	{
		if (data->map[data->player->y - 1][data->player->x] == 'C')
			data->items->collec -= 1;
		data->map[data->player->y][data->player->x] = '0';
		data->player->y -= 1;
		data->map[data->player->y][data->player->x] = 'P';
	}
	if (data->map[data->e_y][data->e_x] != 'P')
		data->map[data->e_y][data->e_x] = 'E';
}

void	move_down(t_data *data)
{
	if (data->map[data->player->y + 1][data->player->x] != '1')
	{
		if (data->map[data->player->y + 1][data->player->x] == 'C')
			data->items->collec -= 1;
		data->map[data->player->y][data->player->x] = '0';
		data->player->y += 1;
		data->map[data->player->y][data->player->x] = 'P';
	}
	if (data->map[data->e_y][data->e_x] != 'P')
		data->map[data->e_y][data->e_x] = 'E';
}

void	move_right(t_data *data)
{
	if (data->map[data->player->y][data->player->x + 1] != '1')
	{
		if (data->map[data->player->y][data->player->x + 1] == 'C')
			data->items->collec -= 1;
		data->map[data->player->y][data->player->x] = '0';
		data->player->x += 1;
		data->map[data->player->y][data->player->x] = 'P';
	}
	if (data->map[data->e_y][data->e_x] != 'P')
		data->map[data->e_y][data->e_x] = 'E';
}

void	move_left(t_data *data)
{
	if (data->map[data->player->y][data->player->x - 1] != '1')
	{
		if (data->map[data->player->y][data->player->x - 1] == 'C')
			data->items->collec -= 1;
		data->map[data->player->y][data->player->x] = '0';
		data->player->x -= 1;
		data->map[data->player->y][data->player->x] = 'P';
	}
	if (data->map[data->e_y][data->e_x] != 'P')
		data->map[data->e_y][data->e_x] = 'E';
}