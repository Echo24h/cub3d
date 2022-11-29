/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:06:16 by gborne            #+#    #+#             */
/*   Updated: 2022/11/08 23:06:31 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "cub3D.h"

//INIT.C
void	init(char *path, t_data *data);
void	init_win(t_data *ptr);
void	init_texture(t_img *img);
void	init_data(t_data *data);
void	init_obj(t_data *data, t_obj *obj, int widht, int height);
void	init_player(t_data *data);
void	init_raycast(t_data *data);

//PARSING/GET.C
int		get_texture(int fd, t_data *data);
int		get_map(int fd, t_data *data);
char	*get_name(char *path);
int		*get_color_list(t_texture sprite, int colone);
int		get_collumn(t_point *raypoint, int actual);

//PARSING/CHECK.C
int		check_texture(t_data *data);
int		check_file(int fd, char *path);
int		check_map(char **map);
int		check_rgb(char **str);
int		check_rgb_min(char **split, int i);
char	*map_cmp(double y, double x, char *handle, t_data *data);
			//CHECK SI LA POSITION DANS LA MAP EST UN CARACTERE DE HANDLE

#endif