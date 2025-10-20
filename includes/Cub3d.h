/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:08:19 by alechin           #+#    #+#             */
/*   Updated: 2025/10/20 13:32:43 by alechin          ###   ########.fr       */
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

typedef struct s_main
{
	void			*mlx_pointer;
	void			*win_pointer;
	struct s_sprite	*sprites;
}	t_main;

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