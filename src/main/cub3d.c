/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:07:55 by alechin           #+#    #+#             */
/*   Updated: 2026/02/04 20:08:33 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Execution.h"
#include "Parsing.h"

void	error2exit(char *message, int status)
{
	perror(message);
	exit(status);
}

static void	init_map(t_map *map)
{
	map->width = 10;
	map->height = 10;
	map->player_card = false;
	map->layout = malloc(sizeof(char *) * 11);
	map->layout[0] = ft_strdup("1111111111");
	map->layout[1] = ft_strdup("1000000001");
	map->layout[2] = ft_strdup("1000000001");
	map->layout[3] = ft_strdup("1000000001");
	map->layout[4] = ft_strdup("1000000001");
	map->layout[5] = ft_strdup("1000000001");
	map->layout[6] = ft_strdup("1000000001");
	map->layout[7] = ft_strdup("1000000001");
	map->layout[8] = ft_strdup("1000000001");
	map->layout[9] = ft_strdup("1111111111");
	map->layout[10] = NULL;
	map->x_position = 4;
	map->y_position = 3;
	map->dir = 'N';
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
	t_main		main;
	t_map		map;
	t_images	*images;

	(void)argc;
	(void)argv;
	ft_memset(&main, 0, sizeof(main));
	ft_memset(&map, 0, sizeof(map));
	init_map(&map);
	images = malloc(sizeof(*images) * 4);
	if (!images)
		return (1);
	ft_memset(images, 0, sizeof(*images) * 4);
	main.images = images;
	main.map = &map;
	if (init_mlx_window(&main))
		return (1);
	if (load_textures(&main))
	{
		printf("Error: Failed to load textures\n");
		return (1);
	}
	init_player(&main);
	printf("Player pos: %.2f, %.2f\n", main.player.pos_x, main.player.pos_y);
	printf("Player dir: %.2f, %.2f\n", main.player.dir_x, main.player.dir_y);
	printf("Map size: %d x %d\n", map.width, map.height);
	setup_hooks(&main);
	mlx_loop(main.mlx_pointer);
	return (0);
}


// int	main(int argc, char *argv[])
// {
// 	t_main		main;
// 	t_map		map;
// 	t_images	*images;

// 	(void)argc;
// 	(void)argv;
// 	ft_memset(&main, 0, sizeof(main));
// 	ft_memset(&map, 0, sizeof(map));

// 	// Hardcode a simple map
// 	map.width = 10;
// 	map.height = 10;
// 	map.player_card = false;
// 	map.layout = malloc(sizeof(char *) * 11);
// 	map.layout[0] = ft_strdup("1111111111");
// 	map.layout[1] = ft_strdup("1000000001");
// 	map.layout[2] = ft_strdup("1000000001");
// 	map.layout[3] = ft_strdup("1000100001");
// 	map.layout[4] = ft_strdup("1000000001");
// 	map.layout[5] = ft_strdup("1000000001");
// 	map.layout[6] = ft_strdup("1000000001");
// 	map.layout[7] = ft_strdup("1000000001");
// 	map.layout[8] = ft_strdup("1000000001");
// 	map.layout[9] = ft_strdup("1111111111");
// 	map.layout[10] = NULL;

// 	// Hardcode player position (where 'N' is: row 3, col 4)
// 	map.x_position = 1;
// 	map.y_position = 3;
// 	map.dir = 'N';

// 	images = malloc(sizeof(*images) * 4);
// 	if (!images)
// 		return (1);
// 	ft_memset(images, 0, sizeof(*images) * 4);
// 	main.images = images;
// 	main.map = &map;

// 	// Initialize MLX
// 	main.mlx_pointer = mlx_init();
// 	if (!main.mlx_pointer)
// 		return (1);
// 	main.win_pointer = mlx_new_window(main.mlx_pointer, WIDTH, HEIGHT, NAME);
// 	if (!main.win_pointer)
// 		return (1);
// 	main.screen.image = mlx_new_image(main.mlx_pointer, WIDTH, HEIGHT);
// 	main.screen.data = mlx_get_data_addr(main.screen.image,
// 		&main.screen.bpp, &main.screen.line_length, &main.screen.end);
// 	if (load_textures(&main))
// 	{
// 		printf("Error: Failed to load textures\n");
// 		return (1);
// 	}
// 	// Initialize player
// 	init_player(&main);

// 	printf("Player pos: %.2f, %.2f\n", main.player.pos_x, main.player.pos_y);
// 	printf("Player dir: %.2f, %.2f\n", main.player.dir_x, main.player.dir_y);
// 	printf("Map size: %d x %d\n", map.width, map.height);

// 	// Run
// 	mlx_hook(main.win_pointer, 17, 0, close_button, &main);
// 	mlx_loop_hook(main.mlx_pointer, game_loop, &main);
// 	mlx_loop(main.mlx_pointer);
// 	return (0);
// }