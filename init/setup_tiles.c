/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_tiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:09:29 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/08 16:44:03 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	setup_tiles(t_tiles *tiles, void *mlx)
{	
	tiles->empty = mlx_xpm_file_to_image(mlx, EMPTY, tiles->x, tiles->y);
	tiles->collec = mlx_xpm_file_to_image(mlx, RABBIT_D, tiles->x, tiles->y);
	tiles->wall = mlx_xpm_file_to_image(mlx, WALL, tiles->x, tiles->y);
	tiles->player = mlx_xpm_file_to_image(mlx, P_FRONT, tiles->x, tiles->y);
	tiles->end = mlx_xpm_file_to_image(mlx, END_CLOSE, tiles->x, tiles->y);
	tiles->ennemies = mlx_xpm_file_to_image(mlx, HEART_LS, tiles->x, tiles->y);
}
