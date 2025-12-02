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

int parse_file(t_main *main)
{
	char	*line;
	int		texture;
	int		file_count;

	texture = 0;
	file_count = 0;
	while (texture <= 3 || file_count <= 1)
	{
		line = get_next_line(main->mapfile_id);
		if (!line)
			return (free(line), 1);
		main->res = is_texture(main, line, texture);
		if (!main->res)
			return (free_texture_paths(main), 1);
		if (main->res)
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
	if (verify_texture(main, img));
}