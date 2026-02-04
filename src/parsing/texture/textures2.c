/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:58:41 by rpadasia          #+#    #+#             */
/*   Updated: 2026/02/04 14:41:03 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Parsing.h"
#include "Execution.h"

int	load_textures(t_main *main)
{
	main->images[0].image = mlx_xpm_file_to_image(main->mlx_pointer,
			"textures/c3d_castleTownWall01.xpm",
			&main->images[0].width, &main->images[0].height);
	main->images[1].image = mlx_xpm_file_to_image(main->mlx_pointer,
			"textures/c3d_castleTownWall02.xpm",
			&main->images[1].width, &main->images[1].height);
	main->images[2].image = mlx_xpm_file_to_image(main->mlx_pointer,
			"textures/c3d_castleTownWall03.xpm",
			&main->images[2].width, &main->images[2].height);
	main->images[3].image = mlx_xpm_file_to_image(main->mlx_pointer,
			"textures/c3d_castleTownWall04.xpm",
			&main->images[3].width, &main->images[3].height);
	if (!main->images[0].image || !main->images[1].image
		|| !main->images[2].image || !main->images[3].image)
		return (1);
	main->images[0].data = mlx_get_data_addr(main->images[0].image,
			&main->images[0].bpp, &main->images[0].line_length,
			&main->images[0].end);
	main->images[1].data = mlx_get_data_addr(main->images[1].image,
			&main->images[1].bpp, &main->images[1].line_length,
			&main->images[1].end);
	main->images[2].data = mlx_get_data_addr(main->images[2].image,
			&main->images[2].bpp, &main->images[2].line_length,
			&main->images[2].end);
	main->images[3].data = mlx_get_data_addr(main->images[3].image,
			&main->images[3].bpp, &main->images[3].line_length,
			&main->images[3].end);
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
	int				y;
	int				tex_idx;
	int				tex_y;
	double			step;
	double			tex_pos;
	unsigned int	color;

	y = 0;
	while (y < main->current_ray.draw_start)
		put_pixel(main, x, y++, 0x87CEEB);
	tex_idx = select_texture(&main->current_ray);
	step = 1.0 * main->images[tex_idx].height / main->current_ray.line_height;
	tex_pos = (main->current_ray.draw_start - HEIGHT / 2
			+ main->current_ray.line_height / 2) * step;
	while (y < main->current_ray.draw_end)
	{
		tex_y = (int)tex_pos & (main->images[tex_idx].height - 1);
		tex_pos += step;
		color = get_texture_pixel(&main->images[tex_idx],
				main->current_ray.tex_x, tex_y);
		if (main->current_ray.side == 1)
			color = (color >> 1) & 0x7F7F7F;
		put_pixel(main, x, y++, color);
	}
	while (y < HEIGHT)
		put_pixel(main, x, y++, 0x8B4513);
}