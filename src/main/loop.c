/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 21:47:45 by rpadasia          #+#    #+#             */
/*   Updated: 2026/02/04 14:51:01 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Execution.h"
#include "Parsing.h"

void	clear_screen(t_main* main)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(main, x, y, REALBLACK);
			x++;
		}
		y++;
	}
}

void	put_pixel(t_main *main, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = main->screen.data + (y * main->screen.line_length
			+ x * (main->screen.bpp / 8));
	*(unsigned int *)dst = color;
}

int	game_loop(t_main *main)
{
	int	x;

	update_player_position(main);
	clear_screen(main);
	x = 0;
	while (x < WIDTH)
	{
		cast_ray(main, x);
		draw_wall_stripe_textured(main, x);
		x++;
	}
	mlx_put_image_to_window(main->mlx_pointer,
		main->win_pointer, main->screen.image, 0, 0);
	// display_fps(main);
	return (0);
}