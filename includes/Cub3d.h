/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:08:19 by alechin           #+#    #+#             */
/*   Updated: 2025/12/02 16:05:04 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/time.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

/*	--	CONTROLS	--	*/
# define UP 87
# define DOWN 83
# define LEFT 65
# define RIGHT 68
# define ESCAPE 65307
# define SPACE 32

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

typedef enum e_identifier
{
	N_IDENTIFIER = 'NO',
	S_IDENTIFIER = 'SO',
	W_IDENTIFIER = 'WE',
	E_IDENTIFER = 'EA',
	FLOOR_COLOR = 'F',
}	t_identifier;

typedef struct s_map
{
	char	**maps;
}	t_map;

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

typedef struct s_main
{
	void			*mlx_pointer;
	void			*win_pointer;
	bool			res;
	int				mapfile_id;
	int				map_start;
	char			*mapfile_name;
	char			**texture_path;
	t_time			time;
	t_images		screen;
	t_state_machine	*states;
	struct s_sprite	*sprites;
}	t_main;

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
	char	**layout;
}	t_map;

typedef struct s_time
{
	time_t	last_fps;
	int		current_fps;
	int		frame_counts;
}	t_time;

/*	--	GENERAL	--	*/
void	error2exit(char *message, int status);

t_main	*struct_main(void);

#endif