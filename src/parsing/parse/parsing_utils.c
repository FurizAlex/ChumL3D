/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:54:55 by alechin           #+#    #+#             */
/*   Updated: 2026/03/04 11:18:09 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parsing.h"
#include "Cub3d.h"

int	overcharge(int count, char **lines, char *temp)
{
	if (count >= 255)
		return (free(temp),
			free_lines(lines, count),
			error2exit("Error: Map too large\n", 1), -1);
	return (0);
}

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
