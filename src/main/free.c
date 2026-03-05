/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:54:05 by alechin           #+#    #+#             */
/*   Updated: 2026/03/05 17:17:36 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Parsing.h"

static void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < map->height)
	{
		free(map->layout[i]);
		i++;
	}
	free(map->layout);
}

void	clean_free(t_main *main)
{
	if (!main)
		return ;
	free_map(main->map);
	//free(main->images);S
	//free(main->texture_path);s
	get_next_line(-1);
}
