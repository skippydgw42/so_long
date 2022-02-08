/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:47:37 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/08 16:14:00 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	dir_up(void *mlx, t_tiles *tiles, int step)
{
	if (step == 0)
		tiles->player = mlx_xpm_file_to_image(mlx, P_B_LEFT, tiles->x, tiles->y);
	else if (step ==1)
		tiles->player = mlx_xpm_file_to_image(mlx, P_BACK, tiles->x, tiles->y);
	else if (step == 2)
		tiles->player = mlx_xpm_file_to_image(mlx, P_B_RIGHT, tiles->x, tiles->y);
}

void	dir_down(void *mlx, t_tiles *tiles, int step)
{
	if (step == 0)
		tiles->player = mlx_xpm_file_to_image(mlx, P_F_LEFT, tiles->x, tiles->y);
	else if (step ==1)
		tiles->player = mlx_xpm_file_to_image(mlx, P_FRONT, tiles->x, tiles->y);
	else if (step == 2)
		tiles->player = mlx_xpm_file_to_image(mlx, P_F_RIGHT, tiles->x, tiles->y);
}

void	dir_right(void *mlx, t_tiles *tiles, int step)
{
	if (step == 0)
		tiles->player = mlx_xpm_file_to_image(mlx, P_S_LEFT, tiles->x, tiles->y);
	else if (step ==1)
		tiles->player = mlx_xpm_file_to_image(mlx, P_SIDE, tiles->x, tiles->y);
	else if (step == 2)
		tiles->player = mlx_xpm_file_to_image(mlx, P_S_RIGHT, tiles->x, tiles->y);
}

void	dir_left(void *mlx, t_tiles *tiles, int step)
{
	if (step == 0)
		tiles->player = mlx_xpm_file_to_image(mlx, P_LS_LEFT, tiles->x, tiles->y);
	else if (step ==1)
		tiles->player = mlx_xpm_file_to_image(mlx, P_LSIDE, tiles->x, tiles->y);
	else if (step == 2)
		tiles->player = mlx_xpm_file_to_image(mlx, P_LS_RIGHT, tiles->x, tiles->y);
}
