/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:05:29 by gborne            #+#    #+#             */
/*   Updated: 2022/11/08 23:06:03 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "./cub3D.h"

//VECTEUR.C
t_point	new_raycast(t_point start, double angle, t_data *data);
			//Return the point where the raycast intersect the map
t_point	new_ray(t_point last, double len, double angle, t_data *data);
			//Return the point where the raycast stop
t_point	*get_wallsize(double numbers, t_point points, t_data *data);
t_point	dda_raycast(t_point start, t_data *data, double angle);
void	debug_raycast(t_data *data);
double	get_ln(t_point a, t_point b);
t_point	newpoint(double x, double y, char c, int orientation);

#endif
