/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:07:55 by alechin           #+#    #+#             */
/*   Updated: 2025/12/08 15:14:23 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"
#include "Parsing.h"

void	error2exit(char *message, int status)
{
	perror(message);
	exit(status);
}

void	window_handler(t_main **mlx)
{
	return ;
}

int	main(int argc, char *argv[])
{
	t_main		*main;
	t_map		*map;
	t_images	*images;

	if (argc != 2)
		error2exit("Error: Invalid Number of Arguments\n", 0);
	images = malloc(sizeof(*images) * 4);
	if (!images)
		return (perror("malloc"), 1);
	if (parse_scene(&main, &map))
		return (1);
	return (0);
}
