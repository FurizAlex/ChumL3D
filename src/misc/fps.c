/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:44:08 by alechin           #+#    #+#             */
/*   Updated: 2025/12/11 16:17:45 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

time_t	time_dial(void)
{
	struct timeval	time_value;

	gettimeofday(&time_value, NULL);
	return (time_value.tv_sec + time_value.tv_usec * 1e-6);
}

void	update_fps(t_main *main)
{
	time_t	current_time;

	current_time = time_dial();
	main->time.frame_counts++;
	if (current_time - main->time.last_fps >= 1.0)
	{
		main->time.current_fps = main->time.frame_counts;
		main->time.frame_counts = 0;
		main->time.last_fps = current_time;
	}
}

void	display_fps(t_main *main)
{
	char	*fps_text;

	update_fps(main);
	fps_text = ft_itoa(main->time.current_fps);
	mlx_string_put(main->mlx_pointer, main->win_pointer,
		WIDTH - 70, 50, 0x00FF00, fps_text);
	free(fps_text);
}
