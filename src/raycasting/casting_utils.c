/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 22:54:49 by rpadasia          #+#    #+#             */
/*   Updated: 2026/01/09 18:52:01 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Execution.h"
#include "Parsing.h"

void	calc_step_and_side_dist(t_main *main, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (main->player.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - main->player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (main->player.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - main->player.pos_y)
			* ray->delta_dist_y;
	}
}

void	perform_dda(t_main *main, t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;// East-West wall
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;// North-South wall
		}
		if (main->map->layout[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	calculate_wall_height(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_dist_to_wall = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_dist_to_wall = ray->side_dist_y - ray->delta_dist_y;
	ray->line_height = (int)(HEIGHT / ray->perp_dist_to_wall);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

void	draw_wall_stripe(t_main *main, int x)
{
	int		y;
	int		color;

	// Draw ceiling
	y = 0;
	while (y < main->current_ray.draw_start)
		put_pixel(main, x, y++, 0x87CEEB);  // Sky blue
	// Draw wall
	color = (main->current_ray.side == 1) ? 0xAAAAAA : 0xFFFFFF;
	while (y < main->current_ray.draw_end)
		put_pixel(main, x, y++, color);
	// Draw floor
	while (y < HEIGHT)
		put_pixel(main, x, y++, 0x8B4513);  // Brown
}