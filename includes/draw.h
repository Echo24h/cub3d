/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:09:12 by gborne            #+#    #+#             */
/*   Updated: 2022/11/08 23:09:21 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "./cub3D.h"

//SCREEN/IMG.C
void	pixel_put(t_obj *data, int x, int y, int color);

char	*remove_extra_space(char *line);
//SCREEN/DISPLAY.C
int		display_content(t_data *data);
void	draw_ray(t_point *walls_point, t_data *data, t_point ray);

#endif
