/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:45:42 by alechin           #+#    #+#             */
/*   Updated: 2026/02/23 21:34:38 by rpadasia         ###   ########.fr       */
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
	main->map->dir = main->map->layout[j][i];
	main->map->layout[j][i] = '0';
	main->map->x_position = i;
	main->map->y_position = j;
	main->map->player_card = false;
	return (0);
}

/* Calculate line length without newline */
static int	get_line_len(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	return (len);
}

/* Free temporary line storage */
static void	free_lines(char **lines, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (lines[i])
			free(lines[i]);
		i++;
	}
	free(lines);
}

/* Build map array from stored lines */
int	build_map_array(t_map *map, char **lines)
{
	int	i;
	int	j;
	int	len;

	map->layout = malloc((map->height + 1) * sizeof(char *));
	if (!map->layout)
		return (1);
	map->layout[map->height] = NULL;
	j = -1;
	while (++j < map->height)
	{
		map->layout[j] = malloc((map->width + 1) * sizeof(char));
		if (!map->layout[j])
			return (1);
		len = ft_strlen(lines[j]);
		i = -1;
		while (++i < map->width)
		{
			if (i < len && lines[j][i] != '\n' && lines[j][i] != ' ')
				map->layout[j][i] = lines[j][i];
			else
				map->layout[j][i] = '1';
		}
		map->layout[j][i] = '\0';
	}
	return (0);
}

/* Validate map boundaries and find player */
static int	validate_map(t_main *main)
{
	int	i;
	int	j;

	j = -1;
	while (++j < main->map->height)
	{
		i = -1;
		while (++i < main->map->width)
		{
			if (i == 0 || j == 0 || i == main->map->width - 1
				|| j == main->map->height - 1)
			{
				if (main->map->layout[j][i] != '1')
				{
					printf("Error at [%d][%d]: '%c'\n", j, i,
						main->map->layout[j][i]);
					error2exit("Error: The walls aren't enclosed\n", 1);
				}
			}
			else if (main->map->layout[j][i] == 'N'
				|| main->map->layout[j][i] == 'S'
				|| main->map->layout[j][i] == 'W'
				|| main->map->layout[j][i] == 'E')
				player_position(main, i, j);
		}
	}
	return (0);
}

/* Parse map content - read once and store in memory */
int	parse_map_content(t_main *main, t_map *map)
{
	char	*temp;
	char	**lines;
	int		count;

	lines = malloc(sizeof(char *) * 256);
	if (!lines)
		return (1);
	count = 0;
	map->width = 0;
	while (1)
	{
		temp = get_next_line(main->mapfile_id);
		if (!temp)
			break ;
		if (temp[0] == '\n')
		{
			free(temp);
			continue ;
		}
		if (check_valid_map(temp))
			return (free(temp), free_lines(lines, count), 1);
		if (get_line_len(temp) > map->width)
			map->width = get_line_len(temp);
		lines[count++] = temp;
	}
	map->height = count;
	close(main->mapfile_id);
	if (build_map_array(map, lines))
		return (free_lines(lines, count), 1);
	free_lines(lines, count);
	validate_map(main);
	if (map->player_card)
		error2exit("Error: No player in cub\n", 2);
	return (0);
}