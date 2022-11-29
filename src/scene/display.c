/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:47:41 by gborne            #+#    #+#             */
/*   Updated: 2022/11/08 23:31:33 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	draw_ray(t_point *w_points, t_data *data, t_point ray)
{
	double	y;
	int		ratio;
	double	unit_y;

	y = data->s_height;
	w_points[0].y += data->player.h;
	w_points[1].y += data->player.h;
	unit_y = (64.0 / (w_points[1].y - w_points[0].y));
	if (ray.or == 1 || ray.or == 3)
		ratio = (int)ray.y % 64;
	else
		ratio = (int)ray.x % 64;
	while (--y)
	{
		if (y > w_points[1].y)
			pixel_put(&data->obj, w_points->x, y, data->map.f_color);
		else if (y > w_points[0].y)
		{
			w_points->color = data->images.w_sprite[ray.or].ctab[ratio][(int)((y
						- w_points[0].y) * unit_y)];
			pixel_put(&data->obj, w_points->x, y, w_points->color);
		}
		else
			pixel_put(&data->obj, w_points->x, y, data->map.sky_color);
	}
}

void	draw_screen(t_data *data)
{
	init_raycast(data);
	mlx_put_image_to_window(data->mlx, data->win, data->obj.img, 0, 0);
}

int	display_content(t_data *data)
{
	data->player.view.wall_unit = data->map.f_size / 100.0;
	mlx_destroy_image(data->mlx, data->obj.img);
	init_obj(data, &data->obj, data->s_width, data->s_height);
	draw_screen(data);
	return (0);
}
