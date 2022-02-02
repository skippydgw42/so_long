/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:28:29 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/02 13:42:27 by mdegraeu         ###   ########.fr       */
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
	//=======!secure malloc à remonter!===//
	if (!data->items || ! data->vars || !data->tiles || !data->player)
		return (0);
	return (1);
}

int	main(void)
{
	t_data	*data;
	int		fd;
	
	data = malloc(sizeof(*data) + 1);
	fd = open("/Users/mdegraeu/github/projects/so_long/map/map1.ber", O_RDONLY);
	struct_init(data);
	//=======!!free map!!==========//
	game_init(data, fd);
	if (data->items->valid == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	data->vars->mlx = mlx_init();
	data->vars->win = mlx_new_window(data->vars->mlx, ft_strlen(data->map[0]) * 16, ft_modlen(data->map) * 16, "Alice in wonderland");
	setup_tiles(data->tiles, data->vars->mlx);
	put_imgs(data->tiles, data->vars, data->map);
	mlx_loop(data->vars->mlx);

	return (0);
}
