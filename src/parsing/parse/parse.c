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

int	parse_file(t_main *main)
{
	char	*line;
	int		texture;
	int		colors;

	texture = 0;
	colors = 0;
	while (texture < 4 || colors < 2)  // Wait for textures AND colors
	{
		line = get_next_line(main->mapfile_id);
		if (!line)
			return (1);
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			main->map_start++;
			continue ;
		}
		if (line[0] == 'F' || line[0] == 'C')
		{
			colors++;
			free(line);
			main->map_start++;
			continue ;
		}
		if (is_texture(main, line, &texture))
			continue ;
		free(line);
		main->map_start++;
	}
	return (0);
}

int	parse_scene(t_main *main, t_map *map)
{
	int			index;
	t_images	*img;

	index = -1;
	img = struct_image();
	main->texture_path = malloc(sizeof(char *) * 5);
	while (++index < 5)
		main->texture_path[index] = NULL;
	if (parse_file(main))
		return (error2exit("Error: .Cub file error!\n", 2), 2);
	if (verify_texture(main, img))
		return (close_button(main), 1);
	if (parse_map_content(main, map))
		return (close_button(main), 1);
	if (initializing_menu(main))
		return (close_button(main), 1);
	return (0);
}

void	init_player(t_main *main)
{
	main->player.pos_x = main->map->x_position + 0.5;
	main->player.pos_y = main->map->y_position + 0.5;
	// Set direction based on parsed direction (N/S/E/W)
	if (main->map->dir == 'N')
	{
		main->player.dir_x = 0;
		main->player.dir_y = -1;
		main->player.plane_x = 0.66;
		main->player.plane_y = 0;
	}
	else if (main->map->dir == 'E')
	{
		main->player.dir_x = 1;
		main->player.dir_y = 0;
		main->player.plane_x = 0;
		main->player.plane_y = 0.66;
	}
	else if (main->map->dir == 'S')
	{
		main->player.dir_x = 0;
		main->player.dir_y = 1;
		main->player.plane_x = -0.66;
		main->player.plane_y = 0;
	}
	else
	{
		main->player.dir_x = -1;
		main->player.dir_y = 0;
		main->player.plane_x = 0;
		main->player.plane_y = -0.66;
	}
}
