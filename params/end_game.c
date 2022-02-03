/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:06:41 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/03 16:10:08 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	end_game(t_data *data)
{
	if (data->items->collec == 0)
		if (data->player->x == data->e_x && data->player->y == data->e_y)
		{
			mlx_destroy_window(data->vars->mlx, data->vars->win);
			printf("\nYou're in le trou Alice! Enjoy it <3\n\n");
			exit(EXIT_SUCCESS);
		}
}