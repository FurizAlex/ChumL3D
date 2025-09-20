/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:41:26 by alechin           #+#    #+#             */
/*   Updated: 2025/09/19 23:48:57 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

char	*identifier(char *id)
{
	if (id == N_IDENTIFIER)
		return (id);
	else if (id == S_IDENTIFIER)
		return (id);
	else if (id == W_IDENTIFIER)
		return (id);
	else if (id == E_IDENTIFER)
		return (id);
	else if (id == FLOOR_COLOR)
		return (id);
	return (id);
}

char	search(char **path, char *id)
{
	int	i;

	i = 0;
	
}