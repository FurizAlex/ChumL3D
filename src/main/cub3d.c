/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:07:55 by alechin           #+#    #+#             */
/*   Updated: 2025/09/19 23:48:50 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

void	error2exit(char *message, int status)
{
	perror(message);
	exit(status);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		error2exit("Error: Invalid Number of Arguments\n", 0);
}