/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:54:05 by alechin           #+#    #+#             */
/*   Updated: 2026/03/06 17:04:39 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Parsing.h"

static void free_textures(t_main *main)
{
    int i;

    if (!main->images)
        return;

    i = 0;
    while (i < 4)
    {
        if (main->images[i].image)
            mlx_destroy_image(main->mlx_pointer, main->images[i].image);
        i++;
    }
}

static void free_texture_paths(t_main *main)
{
    int i;

    if (!main->texture_path)
        return ;
    i = 0;
    while (i < 4)
    {
        if (main->texture_path[i])
            free(main->texture_path[i]);
        i++;
    }
    free(main->texture_path);
}

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

void clean_free(t_main *main)
{
    if (!main)
        return;
    if (main->screen.image)
		mlx_destroy_image(main->mlx_pointer, main->screen.image);
	free_texture_paths(main);
    free_textures(main);
	free(main->images);
    if (main->win_pointer)
        mlx_destroy_window(main->mlx_pointer, main->win_pointer);
    if (main->mlx_pointer)
    {
        mlx_destroy_display(main->mlx_pointer);
        free(main->mlx_pointer);
    }
    free_map(main->map);
}
