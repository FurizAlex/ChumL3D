/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:40:49 by alechin           #+#    #+#             */
/*   Updated: 2025/12/02 16:15:37 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

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