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
		
	}
}