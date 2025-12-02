/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:08:10 by alechin           #+#    #+#             */
/*   Updated: 2025/12/02 15:37:30 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "Cub3d.h"

/* -- Textures -- */
bool	detect_whitespace(char *string);
void	free_texture_paths(t_main *main);
int		verify_texture(t_main *main, t_images *img);
int		get_xpm_data(t_main *main, t_images *img, int i);
int		texture_detector(char *line);
bool	is_texture(t_main *main, char *line, int *texture);

/* -- BootLoader --  */
t_main		*struct_main(void);
t_images	*struct_image(void);

#endif