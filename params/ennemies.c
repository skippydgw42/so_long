/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:21:31 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/08 16:30:24 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	step_enn(t_data *data)
{
	if (data->card->step == 0)
	{
		data->card->last_step = data->card->step;
		data->card->step++;
	}
	else if (data->card->step == 2)
	{
		data->card->last_step = data->card->step;
		data->card->step--;
	}
	else if (data->card->last_step == 0)
	{
		data->card->last_step = data->card->step;
		data->card->step++;
	}
	else if (data->card->step == 1 && data->card->last_step == 2)
	{
		data->card->last_step = data->card->step;
		data->card->step--;
	}
}

void	enn_dir_left(void *mlx, t_tiles *tiles, int step)
{
	if (step == 0)
		tiles->ennemies = mlx_xpm_file_to_image(mlx, HEART_LS_LF, tiles->x, tiles->y);
	else if (step ==1)
		tiles->player = mlx_xpm_file_to_image(mlx, HEART_LS, tiles->x, tiles->y);
	else if (step == 2)
		tiles->player = mlx_xpm_file_to_image(mlx, HEART_LS_RF, tiles->x, tiles->y);
}

void	enn_dir_right(void *mlx, t_tiles *tiles, int step)
{
	if (step == 0)
		tiles->ennemies = mlx_xpm_file_to_image(mlx, HEART_RS_LF, tiles->x, tiles->y);
	else if (step ==1)
		tiles->ennemies = mlx_xpm_file_to_image(mlx, HEART_RS, tiles->x, tiles->y);
	else if (step == 2)
		tiles->ennemies = mlx_xpm_file_to_image(mlx, HEART_RS_RF, tiles->x, tiles->y);
}

void	update_enn(t_data *data, t_card *card, char **map)
{
	map[card->y][card->x] = '0';
	if (map[card->y][card->x + 1] != '0' && map[card->y][card->x + 1] != 'P')
		card->dir = 1;
	else if (map[card->y][card->x - 1] != '0' && map[card->y][card->x - 1] != 'P')
		card->dir = 0;
	if (card->dir == 0)
	{
		enn_dir_right(data->vars->mlx, data->tiles, data->card->step);
		card->x++;
	}
	else
	{
		enn_dir_left(data->vars->mlx, data->tiles, data->card->step);
		card->x--;
	}
	map[card->y][card->x] = 'X';
}