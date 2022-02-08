/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:28:29 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/08 14:47:06 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_err(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	main(void)
{
	t_data	*data;
	int		fd;
	
	data = malloc(sizeof(*data) + 1);
	fd = open("./map/map1.ber", O_RDONLY);
	if (!data || !struct_init(data))
		return (ft_err());
	//=======!!free map!!==========//
	game_init(data, fd);
	if (data->items->valid == 0)
		return (ft_err());
	data->vars->mlx = mlx_init();
	data->vars->win = mlx_new_window(data->vars->mlx, ft_strlen(data->map[0]) * 64, ft_modlen(data->map) * 64, "Alice in wonderland");
	setup_tiles(data->tiles, data->vars->mlx);
	put_imgs(data->tiles, data->vars, data->map);
	mlx_hook(data->vars->win, 2, 0, ft_key, data);
	mlx_loop_hook(data->vars->mlx, render_frame, data);
	mlx_loop(data->vars->mlx);
	return (0);
}
