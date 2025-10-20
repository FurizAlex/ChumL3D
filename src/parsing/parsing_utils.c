/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:54:55 by alechin           #+#    #+#             */
/*   Updated: 2025/10/20 11:57:56 by alechin          ###   ########.fr       */
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