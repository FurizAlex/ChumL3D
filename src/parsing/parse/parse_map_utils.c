/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:53:10 by alechin           #+#    #+#             */
/*   Updated: 2026/03/04 11:17:34 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Parsing.h"

/* Calculate line length without newline */
int	get_line_len(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	return (len);
}

/* Free temporary line storage */
void	free_lines(char **lines, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

/* Read and store map lines */
int	read_map_lines(t_main *main, t_map *map, char **lines)
{
	char	*temp;
	int		count;

	count = 0;
	map->width = 0;
	while (1)
	{
		temp = get_next_line(main->mapfile_id);
		if (!temp)
			break ;
		overcharge(count, lines, temp);
		if (temp[0] == '\n')
		{
			free(temp);
			continue ;
		}
		if (check_valid_map(temp))
			return (free(temp), free_lines(lines, count), -1);
		if (get_line_len(temp) > map->width)
			map->width = get_line_len(temp);
		lines[count++] = temp;
	}
	map->height = count;
	return (count);
}

static void	fill_map_row(t_map *map, char **lines, int j)
{
	int	i;
	int	len;

	len = ft_strlen(lines[j]);
	i = 0;
	while (i < map->width)
	{
		if (i < len && lines[j][i] != '\n'
			&& lines[j][i] != ' ')
			map->layout[j][i] = lines[j][i];
		else
			map->layout[j][i] = '1';
		i++;
	}
	map->layout[j][i] = '\0';
}

int	build_map_array(t_map *map, char **lines)
{
	int	j;

	map->layout = malloc((map->height + 1) * sizeof(char *));
	if (!map->layout)
		return (1);
	map->layout[map->height] = NULL;
	j = 0;
	while (j < map->height)
	{
		map->layout[j] = malloc((map->width + 1) * sizeof(char));
		if (!map->layout[j])
			return (free_map_rows(map, j), 1);
		fill_map_row(map, lines, j);
		j++;
	}
	return (0);
}
