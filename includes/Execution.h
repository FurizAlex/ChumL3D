/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 21:26:49 by rpadasia          #+#    #+#             */
/*   Updated: 2026/02/04 18:53:42 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "Cub3d.h"
# include <math.h>

void	calc_step_and_side_dist(t_main *main, t_ray *ray);
void	perform_dda(t_main *main, t_ray *ray);
void	calculate_wall_height(t_ray *ray);
void	draw_wall_stripe(t_main *main, int x);
void	cast_ray(t_main *main, int x);


void			clear_screen(t_main *main);
void			put_pixel(t_main *main, int x, int y, int color);
int				game_loop(t_main *main);

int				load_textures(t_main *main);
unsigned int	get_texture_pixel(t_images *tex, int x, int y);
int				select_texture(t_ray *ray);
void			calculate_wall_x(t_main *main, t_ray *ray);
void			draw_wall_stripe_textured(t_main *main, int x);

int		looker_keys(int code, t_main *main);
int 	key_release(int code, t_main *main);
void	update_player_position(t_main *main);
void	move_forward(t_main *main, double speed);
void	move_backward(t_main *main, double speed);
void	strafe_left(t_main *main, double speed);
void	strafe_right(t_main *main, double speed);
void	rotate_player(t_main *main, double rot_speed);


#endif