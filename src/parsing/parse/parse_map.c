/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:45:42 by alechin           #+#    #+#             */
/*   Updated: 2026/03/04 10:47:08 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Parsing.h"

/* Checks for a valid character in the map */
bool	is_valid_map_character(char c)
{
	return (c == ' ' || c == '0' || c == '1'
		|| c == 'N' || c == 'S'
		|| c == 'E' || c == 'W'
		|| c == '\n');
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
	int	i;
	int	j;

	j = 0;
	while (j < main->map->height)
	{
		i = 0;
		while (i < main->map->width)
		{
			if (i == 0 || j == 0
				|| i == main->map->width - 1 || j == main->map->height - 1)
			{
				if (main->map->layout[j][i] != '1')
					error2exit("Error: The walls aren't enclosed\n", 1);
			}
			else if (ft_strchr("NSWE",
					main->map->layout[j][i]))
				player_position(main, i, j);
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
