/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 21:36:58 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/02 11:37:46 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Execution.h"
#include "Parsing.h"

void	cast_ray(t_main *main, int x)
{
	t_ray	indiv;

	indiv.camera_x = 2 * x / (double)WIDTH - 1;
	indiv.dir_x = main->player.dir_x + (main->player.plane_x * indiv.camera_x);
	indiv.dir_y = main->player.dir_y + (main->player.plane_y * indiv.camera_x);
	indiv.map_x = (int)main->player.pos_x;
	indiv.map_y = (int)main->player.pos_y;
	indiv.delta_dist_x = fabs(1 / indiv.dir_x);
	indiv.delta_dist_y = fabs(1 / indiv.dir_y);
	calc_step_and_side_dist(main, &indiv);
	perform_dda(main, &indiv);
	calculate_wall_height(&indiv);
	calculate_wall_x(main, &indiv);
	main->current_ray = indiv;
}
