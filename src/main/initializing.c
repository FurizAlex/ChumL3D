/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:06:20 by alechin           #+#    #+#             */
/*   Updated: 2025/11/30 15:22:03 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

int	initializing_mlx(t_main *main, t_map *map)
{
	main->mlx_pointer = mlx_init();
	if (!main->mlx_pointer)
		return (1);
	main->win_pointer = mlx_new_window(main->mlx_pointer, WIDTH, HEIGHT, NAME);
	
}