/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:28:29 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/01/31 16:46:24 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_vars	vars;
	t_game	game;
	t_data	img;
	int		fd;
	int		x;
	int		y;
	//int		keycode = 27;
	
	fd = open("/Users/mdegraeu/github/projects/so_long/map.ber", O_RDONLY);
	//=======free map!!==========//
	game = game_init(fd);
	if (game.items.valid == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "petit jeu");
	mlx_loop(vars.mlx);
	//ft_close(keycode, &vars);

	//img.img = mlx_new_image(vars.mlx, 1920, 1080);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	img.tiles->empty = mlx_xpm_file_to_image(vars.mlx, EMPTY, &x, &y);
	img.tiles->wall = mlx_xpm_file_to_image(vars.mlx, WALL, &x, &y);

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	return (0);
}
