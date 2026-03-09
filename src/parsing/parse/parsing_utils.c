/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:54:55 by alechin           #+#    #+#             */
/*   Updated: 2026/03/09 10:59:04 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parsing.h"
#include "Cub3d.h"

int	overcharge(int count, int width, char **lines, char *temp)
{
	if (count >= 255)
		return (free(temp), free_lines(lines, count),
			error2exit("Error: Map too tall\n", 1), -1);
	if (width >= 255)
		return (free(temp), free_lines(lines, count),
			error2exit("Error: Map too wide\n", 1), -1);
	return (0);
}

/* Detects Whitespace using a boolean */
bool	detect_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

/* Checks for a valid map */
int	check_valid_map(char *temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
		{
			temp[i] = '\0';
			break ;
		}
		if (!is_valid_map_character(temp[i]))
		{
			printf("Invalid char: '%c' (ASCII %d) at position %d\n",
				temp[i], temp[i], i);
			printf("Line: [%s]\n", temp);
			error2exit("Error: Invalid tiles on map\n", 2);
		}
		i++;
	}
	return (0);
}

/* -- Checks surroundings -- */
void	check_surroundings(t_main *main, int x, int y)
{
	char	**map;

	map = main->map->layout;
	if (x == 0 || y == 0
		|| x == main->map->width - 1
		|| y == main->map->height - 1)
		error2exit("Error: Map not closed\n", 1);
	if (map[y + 1][x] == ' ' || map[y + 1][x] == '\0'
		|| map[y - 1][x] == ' ' || map[y - 1][x] == '\0'
		|| map[y][x + 1] == ' ' || map[y][x + 1] == '\0'
		|| map[y][x - 1] == ' ' || map[y][x - 1] == '\0')
		error2exit("Error: Map not closed\n", 1);
}

void	mismatch_checker(t_map *map, char *temp)
{
	if (map->width > 0 && get_line_len(temp) != map->width)
		error2exit("Error: Map row length mismatch\n", 1);
}
