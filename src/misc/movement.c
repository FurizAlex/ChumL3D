/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:52:47 by rpadasia          #+#    #+#             */
/*   Updated: 2026/02/04 14:53:41 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Execution.h"

/*
** Move forward along the direction vector
** new_x = pos_x + dir_x * speed
** new_y = pos_y + dir_y * speed
*/
void	move_forward(t_main *main, double speed)
{
	double	new_x;
	double	new_y;

	new_x = main->player.pos_x + main->player.dir_x * speed;
	new_y = main->player.pos_y + main->player.dir_y * speed;
	if (main->map->layout[(int)main->player.pos_y][(int)new_x] != '1')
		main->player.pos_x = new_x;
	if (main->map->layout[(int)new_y][(int)main->player.pos_x] != '1')
		main->player.pos_y = new_y;
}

/*
** Move backward (opposite of direction vector)
*/
void	move_backward(t_main *main, double speed)
{
	double	new_x;
	double	new_y;

	new_x = main->player.pos_x - main->player.dir_x * speed;
	new_y = main->player.pos_y - main->player.dir_y * speed;
	if (main->map->layout[(int)main->player.pos_y][(int)new_x] != '1')
		main->player.pos_x = new_x;
	if (main->map->layout[(int)new_y][(int)main->player.pos_x] != '1')
		main->player.pos_y = new_y;
}

/*
** Strafe left (perpendicular to direction, using plane vector)
*/
void	strafe_left(t_main *main, double speed)
{
	double	new_x;
	double	new_y;

	new_x = main->player.pos_x - main->player.plane_x * speed;
	new_y = main->player.pos_y - main->player.plane_y * speed;
	if (main->map->layout[(int)main->player.pos_y][(int)new_x] != '1')
		main->player.pos_x = new_x;
	if (main->map->layout[(int)new_y][(int)main->player.pos_x] != '1')
		main->player.pos_y = new_y;
}

/*
** Strafe right (perpendicular to direction, using plane vector)
*/
void	strafe_right(t_main *main, double speed)
{
	double	new_x;
	double	new_y;

	new_x = main->player.pos_x + main->player.plane_x * speed;
	new_y = main->player.pos_y + main->player.plane_y * speed;
	if (main->map->layout[(int)main->player.pos_y][(int)new_x] != '1')
		main->player.pos_x = new_x;
	if (main->map->layout[(int)new_y][(int)main->player.pos_x] != '1')
		main->player.pos_y = new_y;
}

/*
** Rotate the player's view using rotation matrix:
** | cos(θ)  -sin(θ) |   | dir_x |
** | sin(θ)   cos(θ) | × | dir_y |
**
** Both direction and plane vectors must be rotated together
** to maintain the correct FOV relationship
*/
void	rotate_player(t_main *main, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cos_rot;
	double	sin_rot;

	cos_rot = cos(rot_speed);
	sin_rot = sin(rot_speed);
	old_dir_x = main->player.dir_x;
	main->player.dir_x = main->player.dir_x * cos_rot
		- main->player.dir_y * sin_rot;
	main->player.dir_y = old_dir_x * sin_rot
		+ main->player.dir_y * cos_rot;
	old_plane_x = main->player.plane_x;
	main->player.plane_x = main->player.plane_x * cos_rot
		- main->player.plane_y * sin_rot;
	main->player.plane_y = old_plane_x * sin_rot
		+ main->player.plane_y * cos_rot;
}
