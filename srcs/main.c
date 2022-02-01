/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:28:29 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/01 16:39:53 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	struct_init(t_data *data)
{
	//=======!!!!!!!!FREE!!!!!!!!=========//
	data = malloc(sizeof(data));
	data->items = malloc(sizeof(t_items));
	data->vars = malloc(sizeof(t_vars));
	data->tiles = malloc(sizeof(t_tiles));
	data->player = malloc(sizeof(t_player));
}

int	main(void)
{
	t_data	*data;
	int		fd;
	
	data = NULL;
	fd = open("/Users/mdegraeu/github/projects/so_long/map.ber", O_RDONLY);
	struct_init(data);
	//=======!!free map!!==========//
	game_init(data, fd);
	if (data->items->valid == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	data->vars->mlx = mlx_init();
	data->vars->win = mlx_new_window(data->vars->mlx, 1920, 1080, "Alice in wonderland");
	setup_tiles(data->tiles, data->vars->mlx);
	put_imgs(data->tiles, data->vars, data->map);
	mlx_loop(data->vars->mlx);

	return (0);
}
