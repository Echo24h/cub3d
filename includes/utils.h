/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:04:50 by gborne            #+#    #+#             */
/*   Updated: 2022/11/08 23:22:34 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "./cub3D.h"

//UTILS.C
int			c_char(char *str, char c);
int			map_error(char **map, int x, int y, int error_type);
char		*char_replace(char *str, char c, char *replace, int do_free);
int			surround(char **map, t_point p, char *set, int border);
char		**ft_tabdup(char **tab, int do_free);
int			rgb_to_int(char *str);
char		*multi_char_remove(char *str, char *c, int do_free);
int			ft_atoi_base(char *str, char *base);
int			count_div(int nb, int ln_base);
int			check_files(t_data *data);
//TEXTURE.C
t_texture	xpm_to_tab(char *path, t_data *d);
int			xpm_color(char **color, char c);

#endif