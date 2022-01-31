/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:29:11 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/01/27 14:58:35 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"

# define true 1

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_tiles
{
	void	*empty;
	void	*wall;
	void	*player;
	void	*collective;
	void	*end;
}	t_tiles;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_tiles	*tiles;
}	t_data;

typedef	struct s_items
{
	int	collec;
	int	exit;
	int	player;
	int	valid;
}	t_items;

typedef	struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_game
{
	char		**map;
	t_items		items;
	t_player	player;
}	t_game;

//============SRCS=============//
t_player	player_init(t_player player, char **map);
t_game		game_init(int fd);
//void		game_init(t_game game, int fd);

//============PARAMS===========//
int			ft_close(int keycode, t_vars *vars);

//===========PARSING===========//
int			map_check(char **map);
char		**map_to_split(int fd);
char		**map_init(int fd);
t_items		check_err(char **map);
int			is_map_closed(char **map);
int			is_rect_map(char **map);

//=============GNL=============//
char		*get_next_line(int fd);

# define WALL "../imgs/box_wall.png"
# define EMPTY "../imgs/ground.png"
# define PLAYER
# define START
# define END

#endif