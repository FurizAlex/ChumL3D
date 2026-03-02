/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 21:31:19 by alechin           #+#    #+#             */
/*   Updated: 2026/02/26 16:13:27 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"
#include "parsing.h"

int	load_single_texture(t_main *main, int i, char *path)
{
	main->images[i].image = mlx_xpm_file_to_image(
			main->mlx_pointer,
			path,
			&main->images[i].width,
			&main->images[i].height);
	if (!main->images[i].image)
		return (1);
	return (0);
}

void	set_texture_data(t_main *main, int i)
{
	main->images[i].data = mlx_get_data_addr(
			main->images[i].image,
			&main->images[i].bpp,
			&main->images[i].line_length,
			&main->images[i].end);
}
