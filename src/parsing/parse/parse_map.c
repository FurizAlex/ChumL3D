/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:45:42 by alechin           #+#    #+#             */
/*   Updated: 2025/12/02 11:31:50 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Parsing.h"

/* Checks for a valid character in the map; is a boolean */
static bool	is_valid_map_character(char is_it)
{
	return (is_it == ' ' || is_it == '0' || is_it == '1'
		|| is_it == 'N' || is_it == 'S' || is_it == 'E' || is_it == 'W');
}

/* It parses the map content.. */
void	parse_map_content(t_map *map, char *line)
{
	const size_t line_length = ft_strlen(line);
	size_t	i;
	
	i = 0;
	while (i < line_length)
	{
		if (!is_valid_map_character(line[i]))
			error2exit("Error: Invalid Map Character", 1);
		i++;
	}
}