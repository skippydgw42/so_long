/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:19:12 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/01/31 17:40:36 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game	game_init(int fd)
{
	t_game	game;
	
	game.map = map_init(fd);
	game.items = check_err(game.map);
	game.player = player_init(game.player, game.map);
	return (game);
}
