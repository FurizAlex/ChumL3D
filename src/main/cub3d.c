/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:07:55 by alechin           #+#    #+#             */
/*   Updated: 2026/03/09 11:06:19 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Execution.h"
#include "Parsing.h"

void	error2exit(char *message, int status)
{
	t_main *main;

	main = struct_main();
	close(main->mapfile_id);
	clean_free(main);
	perror(message);
	exit(status);
}

static int	validate_args(int argc, char *argv[], t_main *main)
{
	int		len;

	if (argc != 2)
	{
		printf("Usage: ./cub3d <map.cub>\n");
		return (1);
	}
	len = ft_strlen(argv[1]);
	if (len < 5 || ft_strncmp(argv[1] + len - 4, ".cub", 4) != 0)
	{
		printf("Error: Map file must have .cub extension\n");
		return (1);
	}
	main->mapfile_name = argv[1];
	main->mapfile_id = open(argv[1], O_RDONLY);
	if (main->mapfile_id < 0)
	{
		perror("Error: Cannot open map file");
		return (1);
	}
	return (0);
}

static int	init_mlx_window(t_main *main)
{
	main->mlx_pointer = mlx_init();
	if (!main->mlx_pointer)
		return (1);
	main->win_pointer = mlx_new_window(main->mlx_pointer, WIDTH, HEIGHT, NAME);
	if (!main->win_pointer)
		return (1);
	main->screen.image = mlx_new_image(main->mlx_pointer, WIDTH, HEIGHT);
	main->screen.data = mlx_get_data_addr(main->screen.image,
			&main->screen.bpp, &main->screen.line_length, &main->screen.end);
	main->screen.width = WIDTH;
	main->screen.height = HEIGHT;
	return (0);
}

static void	setup_hooks(t_main *main)
{
	mlx_hook(main->win_pointer, 17, 0, close_button, main);
	mlx_hook(main->win_pointer, 2, 1L << 0, looker_keys, main);
	mlx_hook(main->win_pointer, 3, 1L << 1, key_release, main);
	mlx_loop_hook(main->mlx_pointer, game_loop, main);
}

int	main(int argc, char *argv[])
{
	t_main	main;
	t_map	map;

	ft_memset(&main, 0, sizeof(main));
	ft_memset(&map, 0, sizeof(map));
	main.map = &map;
	map.player_card = 0;
	if (validate_args(argc, argv, &main))
		return (1);
	if (init_mlx_window(&main))
		return (1);
	main.images = malloc(sizeof(t_images) * 4);
	if (!main.images)
		return (1);
	ft_memset(main.images, 0, sizeof(t_images) * 4);
	if (parse_scene(&main, &map))
		return (1);
	init_player(&main);
	printf("Player pos: %.2f, %.2f\n", main.player.pos_x, main.player.pos_y);
	printf("Player dir: %.2f, %.2f\n", main.player.dir_x, main.player.dir_y);
	printf("Map size: %d x %d\n", map.width, map.height);
	setup_hooks(&main);
	mlx_loop(main.mlx_pointer);
	return (0);
}
