/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:58:41 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/04 18:54:27 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Parsing.h"
#include "Execution.h"

int	load_textures(t_main *main)
{
	if (load_single_texture(main, 0, "textures/c3d_castleTownWall01.xpm"))
		return (1);
	if (load_single_texture(main, 1, "textures/c3d_castleTownWall02.xpm"))
		return (1);
	if (load_single_texture(main, 2, "textures/c3d_castleTownWall03.xpm"))
		return (1);
	if (load_single_texture(main, 3, "textures/c3d_castleTownWall04.xpm"))
		return (1);
	set_texture_data(main, 0);
	set_texture_data(main, 1);
	set_texture_data(main, 2);
	set_texture_data(main, 3);
	return (0);
}

/*
** Get pixel color from texture at (x, y)
*/
unsigned int	get_texture_pixel(t_images *tex, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	pixel = tex->data + (y * tex->line_length + x * (tex->bpp / 8));
	return (*(unsigned int *)pixel);
}

/*
** Select which texture to use based on wall side and ray direction
** side 0 = hit vertical gridline (East/West wall)
** side 1 = hit horizontal gridline (North/South wall)
*/
int	select_texture(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			return (3);
		return (2);
	}
	else
	{
		if (ray->dir_y > 0)
			return (1);
		return (0);
	}
}

/*
** Calculate the exact X coordinate where the ray hit the wall (0.0 to 1.0)
** Then convert to texture X coordinate
*/
void	calculate_wall_x(t_main *main, t_ray *ray)
{
	double	wall_x;
	int		tex_idx;

	if (ray->side == 0)
		wall_x = main->player.pos_y + ray->perp_dist_to_wall * ray->dir_y;
	else
		wall_x = main->player.pos_x + ray->perp_dist_to_wall * ray->dir_x;
	wall_x -= floor(wall_x);
	tex_idx = select_texture(ray);
	ray->tex_x = (int)(wall_x * main->images[tex_idx].width);
	if (ray->side == 0 && ray->dir_x > 0)
		ray->tex_x = main->images[tex_idx].width - ray->tex_x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		ray->tex_x = main->images[tex_idx].width - ray->tex_x - 1;
}

/*
** Draw a vertical stripe of the wall with texture
*/
void	draw_wall_stripe_textured(t_main *main, int x)
{
	t_draw	d;

	d.y = draw_ceiling(main, x);
	d.tex_idx = select_texture(&main->current_ray);
	d.step = 1.0 * main->images[d.tex_idx].height
		/ main->current_ray.line_height;
	d.tex_pos = (main->current_ray.draw_start - HEIGHT / 2
			+ main->current_ray.line_height / 2) * d.step;
	draw_textured_wall(main, x, &d);
	draw_floor(main, x, d.y);
}
