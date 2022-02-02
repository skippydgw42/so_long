/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keynput.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:32:12 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/02 16:36:44 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	collec_ct(t_data *data, t_tiles *tiles, t_vars *vars)
{
	int	is_fin;

	is_fin = 0;
	if (data->items->collec == 0)
	{
		is_fin = 1;
		tiles->end = mlx_xpm_file_to_image(vars->mlx, END_OPEN, tiles->x, tiles->y);
	}
	return (is_fin);
}

int	ft_key(int keycode, t_data *data)
{
	// printf("key :%d\n", keycode);
	if (keycode == 13)
		move_up(data);
	if (keycode == 0)
		move_left(data);
	if (keycode == 1)
		move_down(data);
	if (keycode == 2)
		move_right(data);
	collec_ct(data, data->tiles, data->vars);
	// printf("x:%d y:%d\n", data->player->x, data->player->y);
	// printf("collec :%d\n\n", data->items->collec);
	put_imgs(data->tiles, data->vars, data->map);
	return (1);
}