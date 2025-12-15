/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bootloader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 23:49:53 by alechin           #+#    #+#             */
/*   Updated: 2025/12/11 16:12:21 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

t_main	*struct_main(void)
{
	static t_main	instance;

	return (&instance);
}

t_images	*struct_image(void)
{
	static t_images	instance;

	return (&instance);
}
