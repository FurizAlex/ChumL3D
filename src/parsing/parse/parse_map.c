/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:45:42 by alechin           #+#    #+#             */
/*   Updated: 2026/01/09 17:56:20 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Parsing.h"

/* Checks for a valid character in the map; is a boolean */
bool	is_valid_map_character(char is_it)
{
	return (is_it == ' ' || is_it == '0' || is_it == '1'
		|| is_it == 'N' || is_it == 'S' || is_it == 'E'
		|| is_it == 'W' || is_it == '\n');
}

/* Gets the player position */
int	player_position(t_main *main, int i, int j)
{
	if (!main->map->player_card)
		error2exit("Error: More than one player on the map\n", 1);
	main->map->x_position = i;
	main->map->y_position = j;
	main->map->dir = main->map->layout[j][i];
	main->map->player_card = false;
	return (0);
}

/* It parses the map content.. */
int	parse_map_content(t_main *main, t_map *map)
{
	char	*temp;
	size_t	i;

	i = 0;
	map->width = 0;
	while (1)
	{
		temp = get_next_line(main->mapfile_id);
		if (!temp)
			break ;
		if (temp[0] == '\n')
		{
			free(temp);
			main->map_start++;
			continue ;
		}
		if (check_valid_map(temp))
			return (free(temp), 1);
		if ((int)ft_strlen(temp) > map->width)
			map->width = ft_strlen(temp) - 1;
		free(temp);
		i++;
	}
	map->height = i;
	close(main->mapfile_id);
	get_map_2d_array(main);
	if (check_map_2d_array(main))
		return (1);
	if (map->player_card)
		error2exit("Error: No player in cub\n", 2);
	return (0);
}
