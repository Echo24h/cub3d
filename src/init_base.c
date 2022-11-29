/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:48:42 by gborne            #+#    #+#             */
/*   Updated: 2022/11/08 23:31:10 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void	init_win(t_data *ptr)
{
	ptr->mlx = mlx_init();
	ptr->s_height = 800;
	ptr->s_width = 1250;
	ptr->win = mlx_new_window(ptr->mlx, ptr->s_width, ptr->s_height, "Cub3D");
	ptr->map.map = NULL;
}

void	init_rgb(t_data *data)
{
	data->map.f_color = rgb_to_int(data->images.floor);
	data->map.sky_color = rgb_to_int(data->images.sky);
}

void	init_data(t_data *data)
{
	init_texture(&data->images);
	init_obj(data, &data->obj, data->s_width, data->s_height);
	data->map.f_size = 64;
	data->map.width = -1;
	data->map.height = -1;
}

void	init(char *path, t_data *data)
{
	int	fd;

	fd = open(path, O_RDONLY);
	init_win(data);
	init_data(data);
	if (check_file(fd, path))
		exiting(data);
	if (get_texture(fd, data))
		exiting(data);
	if (get_map(fd, data))
		exiting(data);
	init_rgb(data);
	init_player(data);
	data->map.path = path;
	data->dst_p = (data->s_width / 2) / tan((data->player.view.fov * (M_PI
					/ 180)) / 1.993);
	data->unit = (double)data->player.view.fov / data->s_width;
	close(fd);
}
