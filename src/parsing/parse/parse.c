/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:36:08 by alechin           #+#    #+#             */
/*   Updated: 2025/11/20 15:36:08 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Parsing.h"

static int	handle_line(t_main *main, char *line, int *texture, int *colors)
{
	if (line[0] == '\n' || line[0] == '\0')
	{
		main->map_start++;
		free(line);
		return (0);
	}
	if (line[0] == 'F' || line[0] == 'C')
	{
		(*colors)++;
		main->map_start++;
		free(line);
		return (0);
	}
	if (is_texture(main, line, texture))
		return (1);
	main->map_start++;
	free(line);
	return (0);
}

int	parse_file(t_main *main)
{
	char	*line;
	int		texture;
	int		colors;

	texture = 0;
	colors = 0;
	while (texture < 4 || colors < 2)
	{
		line = get_next_line(main->mapfile_id);
		if (!line)
			return (1);
		if (handle_line(main, line, &texture, &colors))
			continue ;
	}
	return (0);
}

int	parse_scene(t_main *main, t_map *map)
{
	int	index;

	index = -1;
	main->texture_path = malloc(sizeof(char *) * 5);
	if (!main->texture_path)
		return (1);
	while (++index < 5)
		main->texture_path[index] = NULL;
	if (parse_file(main))
	{
		close(main->mapfile_id);
		return (error2exit("Error: .cub file error!\n", 2), 2);
	}
	if (verify_texture(main, main->images))
		return (close_button(main), 1);
	if (parse_map_content(main, map))
		return (close_button(main), 1);
	return (0);
}

void	init_player(t_main *main)
{
	main->player.pos_x = main->map->x_position + 0.5;
	main->player.pos_y = main->map->y_position + 0.5;
	if (main->map->dir == 'N')
		set_north(main);
	else if (main->map->dir == 'E')
		set_east(main);
	else if (main->map->dir == 'S')
		set_south(main);
	else
		set_west(main);
}
