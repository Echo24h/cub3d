/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:48:55 by gborne            #+#    #+#             */
/*   Updated: 2022/11/08 23:30:58 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

t_point	get_step(double angle, t_data *data)
{
	t_point	step;

	step.x = 1 / tan(angle) * (double)data->map.f_size;
	step.y = tan(angle) * (double)data->map.f_size;
	if (sin(angle) < 0.00)
		step.x *= -1;
	return (step);
}

t_point	get_celldist(t_point start, double fsize, double angle)
{
	t_point	d;
	t_point	cell_pos;

	cell_pos.x = (int)(start.x / fsize) *fsize;
	cell_pos.y = (int)(start.y / fsize) *fsize;
	d.x = start.x - cell_pos.x;
	d.y = start.y - cell_pos.y;
	if (sin(angle) >= 0.00)
		d.y = -(fsize - d.y);
	if (cos(angle) < 0.00)
		d.x = (fsize - d.x);
	return (d);
}

static t_point	transform(double angle, t_point *pos)
{
	t_point	off;

	off = newpoint(-1, -1, 0, 0);
	if (cos(angle) > 0.00)
	{
		off.x = 1;
		pos[1].or = 3;
	}
	if (sin(angle) > 0.00)
	{
		off.y = 1;
		pos[0].or = 0;
	}
	return (off);
}

t_point	dda_raycast(t_point start, t_data *data, double angle)
{
	t_point	d;
	t_point	step;
	t_point	*pos;
	t_point	off;

	pos = malloc(2 * sizeof(t_point));
	pos[0] = newpoint(start.x, start.y, '1', 2);
	pos[1] = newpoint(start.x, start.y, '1', 1);
	d = get_celldist(pos[0], F_SIZE, angle);
	step = get_step(angle, data);
	off = transform(angle, pos);
	pos[0] = newpoint(pos[0].x + (-d.y / tan(angle)), pos[0].y
			- d.y, pos[0].car, pos[0].or);
	pos[1] = newpoint(pos[1].x + ((double)F_SIZE - d.x) * off.x, pos[1].y
			- (-((double)F_SIZE - d.x) * tan(angle))
			* off.x, pos[1].car, pos[1].or);
	while (!map_cmp(pos[0].y + off.y, pos[0].x, "1", data))
		pos[0] = newpoint(pos[0].x + step.x, pos[0].y - F_SIZE * -off.y,
				pos[0].car, pos[0].or);
	while (get_ln(data->player.pos, pos[1]) < get_ln(data->player.pos, pos[0])
		&& !map_cmp(pos[1].y, pos[1].x + off.x, "1", data))
		pos[1] = newpoint(pos[1].x + F_SIZE * off.x, pos[1].y + step.y * off.x,
				pos[1].car, pos[1].or);
	return (choose_point(pos, data, off));
}

t_point	new_raycast(t_point start, double angle, t_data *data)
{
	t_point	end;

	end = start;
	end = dda_raycast(end, data, angle);
	if (end.car == ' ')
		end.car = '1';
	return (end);
}
