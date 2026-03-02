/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_passes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:23:14 by alechin           #+#    #+#             */
/*   Updated: 2026/02/26 16:08:39 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"
#include "Parsing.h"
#include "Execution.h"

int	draw_ceiling(t_main *main, int x)
{
	int	y;

	y = 0;
	while (y < main->current_ray.draw_start)
	{
		put_pixel(main, x, y, 0x87CEEB);
		y++;
	}
	return (y);
}

void	draw_floor(t_main *main, int x, int y)
{
	while (y < HEIGHT)
	{
		put_pixel(main, x, y, 0x8B4513);
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
