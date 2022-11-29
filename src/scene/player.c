/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:47:57 by gborne            #+#    #+#             */
/*   Updated: 2022/11/08 23:31:27 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	move_player(t_data *d, int key)
{
	t_point	p;
	double	angle;

	angle = d->player.dir;
	if (key == 1)
		angle -= d->s_width * ((180.0 / d->s_width * 0.0175));
	else if (key == 0)
		angle -= d->s_width * ((90.0 / d->s_width * 0.0175));
	else if (key == 2)
		angle += d->s_width * ((90.0 / d->s_width * 0.0175));
	p = new_ray(d->player.pos, d->player.speed + 10, angle, d);
	if (!map_cmp(p.y, p.x, "1", d))
	{
		p = new_ray(d->player.pos, d->player.speed, angle, d);
		d->player.pos = p;
	}
	return (1);
}

void	rotate_view(t_data *data, int key)
{
	if (key == 124)
		data->player.view.angle += data->player.x_sensi;
	else if (key == 123)
		data->player.view.angle -= data->player.x_sensi;
}
