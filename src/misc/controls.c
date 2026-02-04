/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:40:49 by alechin           #+#    #+#             */
/*   Updated: 2026/02/04 18:54:28 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Execution.h"

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
	close(main->mapfile_id);
	exit(0);
}

/* -- MOVEMENT KEYS FOR.. moving & ARROW KEYS FOR ROTATING PLANE -- */
int	looker_keys(int code, t_main *main)
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

int key_release(int code, t_main *main)
{
	if (code == UP)
		main->states.up = false;
	if (code == DOWN)
		main->states.down = false;
	if (code == LEFT)
		main->states.left = false;
	if (code == RIGHT)
		main->states.right = false;
	if (code == LEFT_L_ARROW)
		main->states.rotate_left = false;
	if (code == RIGHT_R_ARROW)
		main->states.rotate_right = false;
	return (0);
}

/* -- DOOR TOGGLE NEEDS TO BE MADE --
	-- Essentially the 'release' keys -- */
// int	utility_keys(int code, t_main *main)
// {
// 	if (code == ESCAPE)
// 		close_button(main);
// 	if (code == SPACE)
// 		main->states.menu_toggle = !main->states.menu_toggle;
// 	if (code == MINIMAP)
// 		main->states.minimap_toggle = !main->states.minimap_toggle;
// 	return (0);
// }

/*
** Update player position based on current movement states
** Called every frame in game_loop
*/
void	update_player_position(t_main *main)
{
	double	move_speed;
	double	rot_speed;

	move_speed = MOVEMENT_SPEED;
	rot_speed = ROTATION_SPEED;
	if (main->states.up)
		move_forward(main, move_speed);
	if (main->states.down)
		move_backward(main, move_speed);
	if (main->states.left)
		strafe_left(main, move_speed);
	if (main->states.right)
		strafe_right(main, move_speed);
	if (main->states.rotate_left)
		rotate_player(main, rot_speed);
	if (main->states.rotate_right)
		rotate_player(main, -rot_speed);
}