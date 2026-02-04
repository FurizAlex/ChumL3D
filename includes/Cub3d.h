/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:08:19 by alechin           #+#    #+#             */
/*   Updated: 2026/02/04 20:05:36 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/time.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"


/*	--	CONTROLS	--	*/
/* -- WASD --*/
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
/* -- LEFT ARROW & RIGHT ARROW -- */
# define LEFT_L_ARROW 65361
# define RIGHT_R_ARROW 65363
/* -- PRETTY SELF-EXPLANETARY -- */
# define ESCAPE 65307
# define SPACE 32
/* -- E -- */
# define DOOR 101
/* -- M -- */
# define MINIMAP 109
/* -- KEY TYPE -- */
# define PRESS 2
# define RELEASE 3

/* --  SCREEN SPACE  -- */
# define NAME "ChumL3D"
# define WIDTH 1280
# define HEIGHT 720
# define TILE_SIZE 16
# define TILE_OFFSET 1
# define PLAYER_SIZE 10
# define RAY_STEP 0.005

/* --  MOVEMENT  -- */
# define FOV 90
# define MOVEMENT_SPEED 0.03
# define ROTATION_SPEED 0.03
# define MOUSE_SENSITIVITY 0.005

/* --  MAPS  -- Ryan you deal with this k? */
# define MAP_OFFSET NULL
# define MAP_RAY_COUNT NULL
# define WIDTH_TILES 16
# define HEIGHT_TILES 16

/* --  COLORS  -- */
# define WALL_COLOR 0xFFFFFF
# define REALBLACK 0x000000
/*# define FLOOR_COLOR 0xFFFFFF*/
# define PLAYER_COLOR 0xFFFFFF
# define MAP_RAY_COLOR 0xFFFFFF

/*	--	STRUCTS	& ENUMS	--	*/
typedef enum e_walls
{
	NORTH = 'N',
	SOUTH = 'S',
	WEST = 'W',
	EAST = 'E',
	WALL = '1',
	EMPTY = '0',
}	t_walls;

typedef struct s_images
{
	void	*image;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		line_length;
	int		end;
}	t_images;

typedef struct s_map
{
	int		width;
	int		height;
	int		dir;
	int		x_position;
	int		y_position;
	bool	player_card;
	char	**layout;
}	t_map;

typedef struct s_time
{
	time_t	last_fps;
	int		current_fps;
	int		frame_counts;
}	t_time;

typedef enum e_identifier
{
	N_IDENTIFIER = 'N',
	S_IDENTIFIER = 'S',
	W_IDENTIFIER = 'W',
	E_IDENTIFER = 'E',
	FLOOR_COLOR = 'F',
}	t_identifier;

typedef struct s_sprite
{
	void	*temp;
}	t_sprite;

typedef struct s_state_machine
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	bool	rotate_left;
	bool	rotate_right;
	bool	minimap_toggle;
	bool	menu_toggle;
}	t_state_machine;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		tex_x;
	int		tex_y;
	double	side_dist_x;//Distance to next X gridline
	double	side_dist_y;// Distance to next Y gridline
	double	delta_dist_x;// Distance between X gridlines
	double	delta_dist_y;// D btwn Y gridlines
	double	perp_dist_to_wall;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;//NS or EW only rmbr
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_main
{
	void			*mlx_pointer;
	void			*win_pointer;
	bool			res;
	int				mapfile_id;
	int				map_start;
	char			*mapfile_name;
	char			**texture_path;
	t_ray			current_ray;
	t_player		player;
	t_map			*map;
	t_time			time;
	t_images		*images;
	t_images		screen;
	t_images		menu;
	t_state_machine	states;
	struct s_sprite	*sprites;
}	t_main;


/*	--	GENERAL	--	*/
void	error2exit(char *message, int status);

t_main	*struct_main(void);
int		initializing_mlx(t_main *main, t_map *map);
int 	initializing_menu(t_main *main);

#endif