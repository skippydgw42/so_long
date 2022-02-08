/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:19:12 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/08 16:12:01 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	struct_init(t_data *data)
{
	//=======!!!!!!!!FREE!!!!!!!!=========//
	data->items = malloc(sizeof(t_items) + 1);
	data->vars = malloc(sizeof(t_vars) + 1);
	data->tiles = malloc(sizeof(t_tiles) + 1);
	data->player = malloc(sizeof(t_player) + 1);
	data->card = malloc(sizeof(t_card) + 1);
	//=======!secure malloc à remonter!===//
	if (!data->items || ! data->vars || !data->tiles || !data->player || !data->card)
		return (0);
	return (1);
}

void	game_init(t_data *data, int fd)
{	
	map_init(data, fd);
	check_err(data);
	player_init(data, data->map);
	ennemies_init(data, data->map);
	data->step = 0;
}
