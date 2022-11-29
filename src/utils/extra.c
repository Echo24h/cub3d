/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:48:13 by gborne            #+#    #+#             */
/*   Updated: 2022/11/08 23:31:20 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

char	get_caractere(t_point point, t_data *data)
{
	int	x;
	int	y;

	x = (int)(point.x / data->map.f_size);
	y = (int)(point.y / data->map.f_size);
	return (data->map.map[y][x]);
}

int	grid_comp(t_point src, t_point to_check, t_data *data)
{
	t_point	tile;
	t_point	search;

	tile.x = src.x / data->map.f_size;
	tile.y = src.x / data->map.f_size;
	search.x = to_check.x / data->map.f_size;
	search.y = to_check.x / data->map.f_size;
	(void)data;
	if ((int)(tile.x) == (int)search.x)
		if ((int)tile.y == (int)search.y)
			return (0);
	return (1);
}

double	get_ln(t_point a, t_point b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}

t_point	*get_wallsize(double number, t_point points, t_data *data)
{
	double	project_size;
	double	top_pos;
	double	lng;
	double	angle;
	t_point	*wallpos;

	wallpos = malloc(sizeof(t_point) * 2);
	angle = data->unit * number - ((double)data->player.view.fov / 2.0);
	number = data->s_width - number;
	lng = cos(angle * (M_PI / 180.0)) * get_ln(data->player.pos, points);
	project_size = (data->map.f_size / lng * data->dst_p);
	top_pos = ((data->s_height / 2.0) - (project_size / 2.0));
	wallpos[0].x = number;
	wallpos[0].y = top_pos;
	wallpos[1].x = number;
	wallpos[1].y = top_pos + project_size;
	return (wallpos);
}

char	*map_cmp(double y, double x, char *handle, t_data *data)
{
	if (x < 0 || y < 0 || x > data->map.width * data->map.f_size
		|| y > data->map.height * data->map.f_size)
		return (" ");
	return (ft_strchr(handle, data->map.map[(int)(y / data->map.f_size)][(int)(x
		/ data->map.f_size)]));
}
