/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:29:11 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/01 16:39:01 by mdegraeu         ###   ########.fr       */
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
	void	*img;
	void	*empty;
	void	*wall;
	void	*player;
	void	*collec;
	void	*end;
	int		x[1];
	int		y[1];
}	t_tiles;

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

typedef struct s_data
{
	char		**map;
	t_vars		*vars;
	t_tiles		*tiles;
	t_items		*items;
	t_player	*player;
}	t_data;

//============SRCS=============//
void		player_init(t_player *player, char **map);
void		game_init(t_data *data, int fd);

//============ADD=======//
//imgs setup//
void		setup_tiles(t_tiles *tiles, void *mlx);
void		put_imgs(t_tiles *tiles, t_vars *vars, char **map);

//============PARAMS===========//
int			ft_close(int keycode, t_vars *vars);

//===========PARSING===========//
int			map_check(char **map);
char		**map_to_split(int fd);
char		**map_init(int fd);
void		check_err(t_data *data);
int			is_map_closed(char **map);
int			is_rect_map(char **map);

//=============GNL=============//
char		*get_next_line(int fd);

//=============PNG LINK=========//
# define WALL "../imgs/wall/forest.xpm"
# define TREE "../imgs/wall/tree.xpm"
# define EMPTY "../imgs/ground/grass9.xpm"
# define PLAYER "../imgs/player/girl_front.xpm"
# define COLLEC "../imgs/collect/white_rabbit.xpm"
# define END_CLOSE "../imgs/exit/rabbit_hole_close.xpm"
# define END_OPEN "../imgs/exit/tabbit_hole_open.xpm"

#endif