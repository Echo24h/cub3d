/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:48:47 by gborne            #+#    #+#             */
/*   Updated: 2022/11/08 23:31:06 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void	init_obj(t_data *data, t_obj *obj, int widht, int height)
{
	obj->img = mlx_new_image(data->mlx, widht, height);
	obj->addr = mlx_get_data_addr(obj->img, &obj->bits_per_pixel,
			&obj->line_length, &obj->endian);
}

void	init_texture(t_img *img)
{
	int	i;

	i = -1;
	img->wall = malloc(sizeof(void *) * 5);
	img->wall[4] = NULL;
	while (++i < 4)
		img->wall[i] = NULL;
	img->floor = NULL;
	img->sky = NULL;
}

void	get_player_pos(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y >= 0 && data->map.map[y++])
	{
		x = -1;
		while (y >= 0 && data->map.map[y][++x])
		{
			if (ft_strchr("NSEW", data->map.map[y][x]))
			{
				data->player.pos.x = x * data->map.f_size;
				data->player.pos.y = y * data->map.f_size;
				data->player.view.angle -= (90.0 * 0.0175) / 1.8;
				if (data->map.map[y][x] == 'E')
					data->player.view.angle += (90.0 * 0.0175);
				else if (data->map.map[y][x] == 'W')
					data->player.view.angle -= (90.0 * 0.0175);
				else if (data->map.map[y][x] == 'S')
					data->player.view.angle += 2 * (90.0 * 0.0175);
				data->map.map[y][x] = '0';
				y = -1;
			}
		}
	}
}

void	init_player(t_data *data)
{
	data->player.view.angle = 0;
	data->player.speed = 10;
	data->player.view.fov = 80;
	data->player.x_sensi = 0.3;
	data->player.y_sensi = 1.0;
	data->player.view.wall_unit = 0;
	get_player_pos(data);
}

void	init_raycast(t_data *data)
{
	int		collumn;
	double	angle;
	t_point	*ray_point;
	t_point	*walls_point;

	ray_point = malloc(sizeof(t_point) * data->s_width);
	collumn = 0;
	angle = data->player.view.angle;
	while (collumn++ < data->s_width)
	{
		ray_point[collumn] = new_raycast(data->player.pos, angle, data);
		if (collumn == data->s_width / 2)
			data->player.dir = angle;
		walls_point = get_wallsize(collumn, ray_point[collumn], data);
		draw_ray(walls_point, data, ray_point[collumn]);
		free(walls_point);
		angle -= ((double)data->player.view.fov / data->s_width * M_PI / 180.0);
	}
	free(ray_point);
}
