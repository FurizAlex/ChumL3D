/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:08:10 by alechin           #+#    #+#             */
/*   Updated: 2026/03/02 11:41:31 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "Cub3d.h"

/* -- Textures -- */
void		free_texture_paths(t_main *main);
int			verify_texture(t_main *main, t_images *img);
int			get_xpm_data(t_main *main, t_images *img, int i);
int			texture_detector(char *line);
bool		is_texture(t_main *main, char *line, int *texture);

/* -- Parsing -- */
const char	*validate_identifier(char *line);
bool		detect_whitespace(char c);
bool		is_valid_map_character(char is_it);
int			check_valid_map(char *temp);
int			check_map_2d_array(t_main *main);
int			get_map_2d_array_xtra(t_main *main);
int			get_map_2d_array(t_main *main);
int			player_position(t_main *main, int i, int j);
int			parse_file(t_main *main);
int			parse_map_content(t_main *main, t_map *map);
int			parse_scene(t_main *main, t_map *map);
int			build_map_array(t_map *map, char **lines);

/* -- Directions -- */
void		set_north(t_main *main);
void		set_east(t_main *main);
void		set_south(t_main *main);
void		set_west(t_main *main);

/* -- Parse Map Utils -- */
int			get_line_len(char *line);
void		free_lines(char **lines, int count);
int			read_map_lines(t_main *main, t_map *map, char **lines);
int			build_map_array(t_map *map, char **lines);

/* -- Texture -- */
int			load_single_texture(t_main *main, int i, char *path);
void		set_texture_data(t_main *main, int i);
int			draw_ceiling(t_main *main, int x);
void		draw_floor(t_main *main, int x, int y);
void		draw_textured_wall(t_main *main, int x, t_draw *d);

/* -- Controls -- */
int			close_button(t_main *main);

/* -- Directions -- */
void		set_north(t_main *main);
void		set_east(t_main *main);
void		set_south(t_main *main);
void		set_west(t_main *main);

/* -- BootLoader --  */
t_main		*struct_main(void);
t_images	*struct_image(void);

/* -- Initialization for Player -- */
void		init_player(t_main *main);

#endif