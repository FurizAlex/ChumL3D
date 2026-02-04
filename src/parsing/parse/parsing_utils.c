/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:54:55 by alechin           #+#    #+#             */
/*   Updated: 2025/12/24 00:47:32 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parsing.h"
#include "Cub3d.h"

/* Detects Whitespace using a boolean */
bool	detect_whitespace(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == ' ' || string[i] == '\t')
			return (true);
		i++;
	}
	return (false);
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
