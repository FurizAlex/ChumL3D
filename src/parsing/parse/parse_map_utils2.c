/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:58:13 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/05 17:13:09 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "Parsing.h"

unsigned int	parse_rgb(char *line)
{
	int		r;
	int		g;
	int		b;
	char	*ptr;

	ptr = line + 2;
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	r = ft_atoi(ptr);
	ptr = ft_strchr(ptr, ',') + 1;
	g = ft_atoi(ptr);
	ptr = ft_strchr(ptr, ',') + 1;
	b = ft_atoi(ptr);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		error2exit("Error: RGB values must be 0-255\n", 1);
	return ((r << 16) | (g << 8) | b);
}

void	increment_map_start(t_main *main, char *line)
{
	main->map_start++;
	free(line);
}
