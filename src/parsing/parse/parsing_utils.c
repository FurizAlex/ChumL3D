/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:54:55 by alechin           #+#    #+#             */
/*   Updated: 2025/12/11 16:20:51 by alechin          ###   ########.fr       */
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
			error2exit("Error: Invalid tiles on map\n", 2);
	}
	return (0);
}
