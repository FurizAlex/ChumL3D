/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:54:05 by alechin           #+#    #+#             */
/*   Updated: 2026/03/04 13:48:32 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"
#include "Parsing.h"

static void    free_map(t_map *map)
{
    int i;

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
	//free(main->images);
	//free(main->texture_path);
	get_next_line(-1);
}
