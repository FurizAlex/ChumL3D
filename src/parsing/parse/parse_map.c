/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:45:42 by alechin           #+#    #+#             */
/*   Updated: 2026/03/07 11:39:50 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Parsing.h"

/* Checks for a valid character in the map */
bool	is_valid_map_character(char c)
{
	return (c == ' ' || c == '0' || c == '1'
		|| c == 'N' || c == 'S'
		|| c == 'E' || c == 'W');
}

/* Gets the player position */
int	player_position(t_main *main, int i, int j)
{
	main->map->player_card++;
	if (main->map->player_card > 1)
		error2exit("Error: More or less than one player on the map\n", 1);
	main->map->dir = main->map->layout[j][i];
	main->map->layout[j][i] = '0';
	main->map->x_position = i;
	main->map->y_position = j;
	return (0);
}

/* Validate map boundaries and find player */
static int	validate_map(t_main *main)
{
	int		i;
	int		j;
	char	tile;

	j = 0;
	while (j < main->map->height)
	{
		i = 0;
		while (i < main->map->width)
		{
			tile = main->map->layout[j][i];
			if (!is_valid_map_character(tile))
				error2exit("Error: Invalid map character\n", 1);
			if (ft_strchr("NSWE", tile))
				player_position(main, i, j);
			if (tile == '0' || ft_strchr("NSWE", tile))
				check_surroundings(main, i, j);
			i++;
		}
		j++;
	}
	if (main->map->player_card == 0)
		error2exit("Error: No player in cub\n", 2);
	return (0);
}

/* Finalize map creation */
static int	finalize_map(t_main *main, t_map *map, char **lines)
{
	if (build_map_array(map, lines))
		return (free_lines(lines, map->height), 1);
	free_lines(lines, map->height);
	validate_map(main);
	return (0);
}

/* Parse map content */
int	parse_map_content(t_main *main, t_map *map)
{
	char	**lines;
	int		count;

	lines = malloc(sizeof(char *) * 1024);
	if (!lines)
		return (1);
	count = read_map_lines(main, map, lines);
	close(main->mapfile_id);
	if (count <= 0)
		return (free(lines), 1);
	if (finalize_map(main, map, lines))
		return (1);
	return (0);
}
