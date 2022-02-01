/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:13:15 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/01 16:38:28 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_imgs(t_tiles *tiles, t_vars *vars, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, tiles->wall, x * 16, y * 16);
				write(1, "ICI\n", 4);
			}
			else if (map[y][x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, tiles->empty, x * 16, y * 16);
			else if (map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, tiles->collec, x * 16, y * 16);
			else if (map[y][x] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, tiles->player, x * 16, y * 16);
			else if (map[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, tiles->end, x * 16, y * 16);
			x++;
		}
		y++;
	}
}