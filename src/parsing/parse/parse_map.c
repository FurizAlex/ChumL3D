/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:45:42 by alechin           #+#    #+#             */
/*   Updated: 2025/12/11 16:20:44 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Parsing.h"

/* Checks for a valid character in the map; is a boolean */
bool	is_valid_map_character(char is_it)
{
	return (is_it == ' ' || is_it == '0' || is_it == '1'
		|| is_it == 'N' || is_it == 'S' || is_it == 'E' || is_it == 'W');
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
		else if (check_valid_map(temp))
			return (free(temp), 1);
		else if ((int)ft_strlen(temp) > map->width)
			map->width = ft_strlen(temp) - 1;
		free(temp);
		i++;
	}
	map->height = 1;
	close(main->mapfile_id);
	get_map_2d_array(main);
	if (check_map_2d_array(main))
		return (1);
	if (map->player_card)
		error2exit("Error: No player in cub\n", 2);
	return (0);
}
