/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_passes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:23:14 by alechin           #+#    #+#             */
/*   Updated: 2026/03/05 17:04:43 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Parsing.h"
#include "Execution.h"

int	draw_ceiling(t_main *main, int x)
{
	int	y;

	y = 0;
	while (y < main->current_ray.draw_start)
	{
		put_pixel(main, x, y, main->ceiling_color);
		y++;
	}
	return (y);
}

void	draw_floor(t_main *main, int x, int y)
{
	while (y < HEIGHT)
	{
		put_pixel(main, x, y, main->floor_color);
		y++;
	}
}

void	draw_textured_wall(t_main *main, int x, t_draw *d)
{
	while (d->y < main->current_ray.draw_end)
	{
		d->tex_y = (int)d->tex_pos;
		d->tex_pos += d->step;
		d->color = get_texture_pixel(
				&main->images[d->tex_idx],
				main->current_ray.tex_x,
				d->tex_y);
		if (main->current_ray.side == 1)
			d->color = (d->color >> 1) & 0x7F7F7F;
		put_pixel(main, x, d->y, d->color);
		d->y++;
	}
}
