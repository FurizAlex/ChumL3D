/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:54:55 by alechin           #+#    #+#             */
/*   Updated: 2026/02/23 21:03:04 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parsing.h"
#include "Cub3d.h"

/* Detects Whitespace using a boolean */
bool	detect_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

/* Checks for a valid map */
int	check_valid_map(char *temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		if (is_valid_map_character(temp[i]))
			i++;
		else
		{
			printf("Invalid char: '%c' (ASCII %d) at position %d\n",
				temp[i], temp[i], i);
			printf("Line: [%s]\n", temp);
			error2exit("Error: Invalid tiles on map\n", 2);
		}
	}
	return (0);
}
