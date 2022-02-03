/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:29:11 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/03 16:08:11 by mdegraeu         ###   ########.fr       */
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
	int			e_x;
	int			e_y;
	int			side;
	int			last_step;
}	t_data;

//============INIT=============//
int			struct_init(t_data *data);
void		game_init(t_data *data, int fd);
void		player_init(t_data *data, char **map);
void		map_init(t_data *data, int fd);
void		setup_tiles(t_tiles *tiles, void *mlx);
void		put_imgs(t_tiles *tiles, t_vars *vars, char **map);

//============ADD=======//
void		ft_free(char **str);
size_t		ft_modlen(char **map);

//============PARAMS===========//
int			ft_key(int keycode, t_data *data);
// int			ft_close(int keycode, t_vars *vars);
void		move_up(t_data *data);
void		move_down(t_data *data);
void		move_right(t_data *data);
void		move_left(t_data *data);
void		ft_step(t_data *data);
void		dir_up(void *mlx, t_tiles *tiles, int side);
void		dir_down(void *mlx, t_tiles *tiles, int side);
void		dir_right(void *mlx, t_tiles *tiles, int side);
void		dir_left(void *mlx, t_tiles *tiles, int side);
void		end_game(t_data *data);

//===========PARSING===========//
int			map_check(char **map);
void		check_err(t_data *data);
int			is_map_closed(char **map);
int			is_rect_map(char **map);

//=============GNL=============//
char		*get_next_line(int fd);

//=============XPM LINK=========//
# define WALL "/Users/mdegraeu/github/projects/so_long/imgs/wall/forest.xpm"
# define TREE "/Users/mdegraeu/github/projects/so_long/imgs/wall/tree.xpm"
# define EMPTY "/Users/mdegraeu/github/projects/so_long/imgs/ground/grass8.xpm"
# define P_FRONT "/Users/mdegraeu/github/projects/so_long/imgs/player/girl_front.xpm"
# define P_F_RIGHT "/Users/mdegraeu/github/projects/so_long/imgs/player/girl_front_rightfeet.xpm"
# define P_F_LEFT "/Users/mdegraeu/github/projects/so_long/imgs/player/girl_front_leftfeet.xpm"
# define P_BACK "/Users/mdegraeu/github/projects/so_long/imgs/player/girl_back.xpm"
# define P_B_RIGHT "/Users/mdegraeu/github/projects/so_long/imgs/player/girl_back_rightfeet.xpm"
# define P_B_LEFT "/Users/mdegraeu/github/projects/so_long/imgs/player/girl_back_leftfeet.xpm"
# define P_SIDE "/Users/mdegraeu/github/projects/so_long/imgs/player/girl_side.xpm"
# define P_S_RIGHT "/Users/mdegraeu/github/projects/so_long/imgs/player/girl_side_rightfeet.xpm"
# define P_S_LEFT "/Users/mdegraeu/github/projects/so_long/imgs/player/girl_side_leftfeet.xpm"
# define P_LSIDE "/Users/mdegraeu/github/projects/so_long/imgs/player/girl_leftside.xpm"
# define P_LS_RIGHT "/Users/mdegraeu/github/projects/so_long/imgs/player/girl_leftside_rightfeet.xpm"
# define P_LS_LEFT "/Users/mdegraeu/github/projects/so_long/imgs/player/girl_leftside_leftfeet.xpm"
# define COLLEC "/Users/mdegraeu/github/projects/so_long/imgs/collect/white_rabbit.xpm"
# define END_CLOSE "/Users/mdegraeu/github/projects/so_long/imgs/exit/rabbit_hole_close.xpm"
# define END_OPEN "/Users/mdegraeu/github/projects/so_long/imgs/exit/rabbit_hole_open.xpm"

#endif