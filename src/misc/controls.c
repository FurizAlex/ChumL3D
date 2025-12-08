/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:40:49 by alechin           #+#    #+#             */
/*   Updated: 2025/12/08 11:18:29 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

/* -- HANDLES THE X BUTTON -- */
int	close_button(t_main *main)
{
	if (main->screen.image)
		mlx_destroy_image(main->mlx_pointer, main->screen.image);
	if (main->mlx_pointer)
		mlx_destroy_window(main->mlx_pointer, main->win_pointer);
	if (main->mlx_pointer)
	{
		mlx_destroy_display(main->mlx_pointer);
		free(main->mlx_pointer);
	}
	close(main->mapfile_name);
	exit(0);
}

/* -- MOVEMENT KEYS FOR.. moving & ARROW KEYS FOR ROTATING PLANE -- */
int	movement_keys(int code, t_main *main)
{
	if (code == UP)
		main->states.up = true;
	if (code == DOWN)
		main->states.down = true;
	if (code == LEFT)
		main->states.left = true;
	if (code == RIGHT)
		main->states.right = true;
	if (code == LEFT_L_ARROW)
		main->states.rotate_left = true;
	if (code == RIGHT_R_ARROW)
		main->states.rotate_right = true;
	return (0);
}

/* -- DOOR TOGGLE NEEDS TO BE MADE -- */
int utility_keys(int code, t_main *main)
{
	if (code == ESCAPE)
		close_button(main);
	if (code == SPACE)
		main->states.menu_toggle = !main->states.menu_toggle;
	if (code == DOOR)
		return (NULL);
	if (code == MINIMAP)
		main->states.minimap_toggle = !main->states.minimap_toggle;
	return (0);
}