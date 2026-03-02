/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:11:06 by alechin           #+#    #+#             */
/*   Updated: 2026/03/02 14:13:46 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Parsing.h"

void	free_map_rows(t_map *map, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(map->layout[i]);
		i++;
	}
	free(map->layout);
}
