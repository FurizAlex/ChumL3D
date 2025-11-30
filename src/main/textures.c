/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:42:58 by alechin           #+#    #+#             */
/*   Updated: 2025/11/28 21:01:13 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	free_texture_paths(t_main *main)
{
	int	i;

	if (!main->texture_path)
		return ;
	i = 0;
	while (i <= 3)
	{
		if (main->texture_path[i])
			free(main->texture_path[i]);
		i++;
	}
	free(main->texture_path);
	main->texture_path = NULL;
}

int	get_xpm_data(t_main *main, t_images *img, int i)
{
	char	*line;
	char	*path;
	char	*newline;

	line = main->texture_path[i];
	path = ft_strchr(line, ' ') + 1;
	newline = ft_strchr(path, '\n');
	if (newline)
		*newline = '\0';
	img[i].image = mlx_xpm_file_to_image(main->mlx_pointer,
					path, &img[i].width, &img[i].height);
	if (!img[i].image)
		return (1);
	img[i].data = mlx_get_data_addr(img[i].image, &img[i].bpp,
					&img[i].line_length, &img[i].end);
	return (0);
}

int	verify_texture(t_main *main, t_images *img)
{
	int	i;

	i = 0;
	while (i <= 3)
	{
		if (!main->texture_path[i])
			error2exit("Error: Texture Error!", 1);
		if (get_xpm_data(main, img, i))
			error2exit("Error: Failed to get xpm data", 1);
		i++;
	}
	return (0);
}

int	texture_detector(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (0);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (0);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (0);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (0);
	return (-1);
}

bool	is_texture(t_main *main, char *line, int *texture)
{
	int	detect_idx;

	detect_idx = texture_detector(line);
	if (detect_idx < 0)
		return (0);
	if (main->texture_path[detect_idx] != NULL)
	{
		free(line);
		error2exit("Error: Texture Error", 1);
	}
	main->texture_path[detect_idx] = line;
	(*texture)++;
	main->map_start++;
	return (1);
}