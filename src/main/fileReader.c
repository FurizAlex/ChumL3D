/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileReader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 23:48:19 by alechin           #+#    #+#             */
/*   Updated: 2025/10/20 11:39:59 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

void	readfile(int argc, char *argv[], t_main	**game)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		error2exit("Error: File doesn't exist bro\n", 0);
	*game = malloc(sizeof(t_main));
	if (!*game)
		error2exit("Error: Struct doesn't exist\n", 0);
	(*game)->sprites = NULL;
}
