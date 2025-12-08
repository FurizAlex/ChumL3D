/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:51:07 by alechin           #+#    #+#             */
/*   Updated: 2025/12/08 10:39:39 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parsing.h"
#include "Cub3d.h"

#define MAX_CONFIGS 6

/* Practically searches through the map to see which character
is which and also removes any whitespace in said line*/
static char	*character_identifier(char *line)
{
	int offset;
	
	offset = 0;
	while (line[offset])
	{
		if (detect_whitespace(line[offset]))
			break;
		offset++;
	}
	return (ft_substr(line, 0, offset));
}

/* Checks all valid identifiers on the map
and return the valid identifier */
const char	*validate_identifier(char *line)
{
	int			i;
	char		*dummy_identifiers;
	const char	*validate_id;
	const static char *validate_ids[MAX_CONFIGS] = {
		"NO", "SO", "WE", "EA", "F", "C"
	};

	i = 0;
	dummy_identifiers = character_identifier(line);
	while (i < MAX_CONFIGS)
	{
		validate_id = validate_ids[i];
		if (ft_strcmp(validate_id, dummy_identifiers) == 0)
		{
			free(dummy_identifiers);
			return (validate_id);
		}
		i++;
	}
	free(dummy_identifiers);
	error2exit("Invalid type identifier\n", 1);
}