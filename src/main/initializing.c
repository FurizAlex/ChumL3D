/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:06:20 by alechin           #+#    #+#             */
/*   Updated: 2025/12/11 16:16:46 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	initializing_mlx(t_main *main, t_map *map)
{
	main->mlx_pointer = mlx_init();
	if (!main->mlx_pointer)
		return (1);
	main->win_pointer = mlx_new_window(main->mlx_pointer, WIDTH, HEIGHT, NAME);
	if (!main->win_pointer)
		return (1);
	mlx_mouse_move(main->mlx_pointer, main->win_pointer, WIDTH / 2, HEIGHT / 2);
	mlx_mouse_hide(main->mlx_pointer, main->win_pointer);
	main->screen.image = mlx_new_image(main->mlx_pointer, WIDTH, HEIGHT);
	main->screen.data = mlx_get_data_addr(main->screen.image,
			&main->screen.bpp, &main->screen.line_length, &main->screen.end);
	main->screen.width = WIDTH;
	main->screen.height = HEIGHT;
	main->map = map;
	return (0);
}

int	initializing_menu(t_main *main)
{
	main->menu.image = mlx_xpm_file_to_image(main->mlx_pointer,
			"textures/c3d_titleScreen.xpm",
			&main->menu.width, &main->menu.height);
	if (main->menu.image == 0)
		error2exit("Error: Couldn't load image\n", 1);
	main->menu.data = mlx_get_data_addr(main->menu.image,
			&main->menu.bpp, &main->menu.line_length, &main->menu.end);
	return (0);
}
