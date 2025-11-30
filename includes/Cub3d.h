/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:08:19 by alechin           #+#    #+#             */
/*   Updated: 2025/11/28 21:01:02 by alechin          ###   ########.fr       */
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
	int				res;
	int				mapfile_id;
	int				map_start;
	char			*mapfile_name;
	char			**texture_path;
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

/*	--	GENERAL	--	*/
void	error2exit(char *message, int status);

t_main	*struct_main(void);

#endif