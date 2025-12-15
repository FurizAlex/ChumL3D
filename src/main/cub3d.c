/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:07:55 by alechin           #+#    #+#             */
/*   Updated: 2025/12/15 12:58:44 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Parsing.h"

static int	verify_arguments(int argc, char *filename, t_main *main)
{
	char	*file_pointer;

	if (argc != 2)
		error2exit("Error: Cub3D only takes in: ./cub3D 'Map Name/map'\n", 1);
	file_pointer = ft_strchr(filename, '.');
	if (!file_pointer || ft_strncmp(file_pointer, ".cub", 5))
		error2exit("Error: Cub3D only takes in: ./cub3D 'Map Name/map'\n", 1);
	main->mapfile_id = open(filename, O_RDONLY);
	if (main->mapfile_id < 0)
		error2exit("Error: The file isn't found in directory'\n", 1);
	main->mapfile_name = filename;
	return (0);
}

static void	window_handler(t_main *main)
{
	mlx_hook(main->win_pointer, 17, 0, close_button, main);
	mlx_hook(main->win_pointer, PRESS, 1L << 0, movement_keys, main);
	mlx_hook(main->win_pointer, RELEASE, 1L << 1, utility_keys, main);
	mlx_loop(main->mlx_pointer);
}

void	error2exit(char *message, int status)
{
	perror(message);
	exit(status);
}

int	main(int argc, char *argv[])
{
	t_main		main;
	t_map		map;
	t_images	*images;

	ft_memset(&main, 0, sizeof(main));
	ft_memset(&map, 0, sizeof(map));
	if (verify_arguments(argc, argv[1], &main))
		return (1);
	images = malloc(sizeof(*images) * 4);
	if (!images)
		return (perror("malloc"), 1);
	ft_memset(images, 0, sizeof(*images) * 4);
	main.images = images;
	main.states.minimap_toggle = true;
	if (initializing_mlx(&main, &map))
		return (1);
	if (parse_scene(&main, &map))
		return (1);
	window_handler(&main);
	return (0);
}
