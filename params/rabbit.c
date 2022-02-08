/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rabbit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:33:03 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/08 16:46:20 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	step_rabbit()
{
	static int	step;
	static int	last_step;

	last_step = step;
	if (step == 0)
	{
		last_step = step;
		step++;
	}
	else if (step == 2)
	{
		last_step = step;
		step--;
	}
	else if (last_step == 0)
	{
		last_step = step;
		step++;
	}
	else if (last_step == 2)
	{
		last_step = step;
		step--;
	}
	return (step);
}

void	anime_rabbit(t_vars *vars, t_tiles *tiles)
{
	if (step_rabbit() == 0)
		tiles->collec = mlx_xpm_file_to_image(vars->mlx, RABBIT_D, tiles->x, tiles->y);
	else if (step_rabbit() == 1)
		tiles->collec = mlx_xpm_file_to_image(vars->mlx, RABBIT_M, tiles->x, tiles->y);
	else if (step_rabbit() == 2)
		tiles->collec = mlx_xpm_file_to_image(vars->mlx, RABBIT_U, tiles->x, tiles->y);
}