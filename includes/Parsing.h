/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:08:10 by alechin           #+#    #+#             */
/*   Updated: 2026/02/04 18:35:57 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "Cub3d.h"

/* -- Textures -- */
bool		detect_whitespace(char *string);
void		free_texture_paths(t_main *main);
int			verify_texture(t_main *main, t_images *img);
int			get_xpm_data(t_main *main, t_images *img, int i);
int			texture_detector(char *line);
bool		is_texture(t_main *main, char *line, int *texture);

/* -- Parsing -- */
const char	*validate_identifier(char *line);
bool		is_valid_map_character(char is_it);
int			check_valid_map(char *temp);
int			check_map_2d_array(t_main *main);
int			get_map_2d_array_xtra(t_main *main);
int			get_map_2d_array(t_main *main);
int			player_position(t_main *main, int i, int j);
int			parse_file(t_main *main);
int			parse_map_content(t_main *main, t_map *map);
int			parse_scene(t_main *main, t_map *map);
bool		detect_whitespace(char *string);
int			build_map_array(t_main *main, t_map *map, char **lines);

/* -- Controls -- */
int			close_button(t_main *main);

/* -- BootLoader --  */
t_main		*struct_main(void);
t_images	*struct_image(void);

/* -- Initialization for Player -- */
void		init_player(t_main *main);

#endif