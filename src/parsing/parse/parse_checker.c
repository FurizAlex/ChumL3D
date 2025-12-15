/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:44:35 by alechin           #+#    #+#             */
/*   Updated: 2025/12/11 16:18:19 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Parsing.h"

/* Is a 2D Array that loops through all the characters and see which
 are valid or not */
int	check_map_2d_array(t_main *main)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++j < main->map->height)
	{
		while (++i < main->map->width)
		{
			if (i == 0 || j == 0
				|| i == main->map->width - 1 || j == main->map->height - 1)
			{
				if (main->map->layout[j][i] != '1')
					error2exit("Error: The walls aren't enclosed", 1);
			}
			else if (main->map->layout[j][i] == 'N'
				|| main->map->layout[j][i] == 'S'
				|| main->map->layout[j][i] == 'W'
				|| main->map->layout[j][i] == 'E')
				if (player_position(main, i, j))
					return (1);
		}
	}
	return (0);
}

int	get_map_2d_array_xtra(t_main *main)
{
	int		i;
	int		j;
	char	*temp;

	i = -1;
	j = -1;
	while (j++ < main->map->height)
	{
		temp = get_next_line(main->mapfile_id);
		if (temp == NULL)
			break ;
		main->map->layout[j] = malloc((main->map->width + 1) * sizeof(int));
		if (!main->map->layout)
			return (1);
		while (++i < main->map->width)
		{
			if (i < (int)ft_strlen(temp) && temp[i] != '\n' && temp[i] != ' ')
				main->map->layout[j][i] = temp[i];
			else
				main->map->layout[j][i] = '1';
		}
		main->map->layout[j][i] = 0;
		free(temp);
	}
	return (0);
}

int	get_map_2d_array(t_main *main)
{
	int		i;
	char	*temp;

	i = 0;
	main->mapfile_id = open(main->mapfile_name, O_RDONLY);
	while (i++ < main->map_start)
	{
		temp = get_next_line(main->map_start);
		if (!temp)
			return (1);
		i++;
	}
	main->map->layout = malloc((main->map->height + 1) * sizeof(int *));
	if (!main->map->layout)
		return (1);
	main->map->layout[main->map->height] = NULL;
	get_map_2d_array_xtra(main);
	return (0);
}
