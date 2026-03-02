/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:18:32 by alechin           #+#    #+#             */
/*   Updated: 2026/03/02 10:43:11 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Parsing.h"

void	set_north(t_main *main)
{
	main->player.dir_x = 0;
	main->player.dir_y = -1;
	main->player.plane_x = 0.66;
	main->player.plane_y = 0;
}

void	set_east(t_main *main)
{
	main->player.dir_x = 1;
	main->player.dir_y = 0;
	main->player.plane_x = 0;
	main->player.plane_y = 0.66;
}

void	set_south(t_main *main)
{
	main->player.dir_x = 0;
	main->player.dir_y = 1;
	main->player.plane_x = -0.66;
	main->player.plane_y = 0;
}

void	set_west(t_main *main)
{
	main->player.dir_x = -1;
	main->player.dir_y = 0;
	main->player.plane_x = 0;
	main->player.plane_y = -0.66;
}
