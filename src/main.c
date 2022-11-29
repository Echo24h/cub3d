/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:48:51 by gborne            #+#    #+#             */
/*   Updated: 2022/11/08 23:31:02 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

t_point	newpoint(double x, double y, char c, int orientation)
{
	t_point	pos;

	pos.x = x;
	pos.y = y;
	pos.car = c;
	pos.or = orientation;
	return (pos);
}

t_point	new_ray(t_point last, double len, double angle, t_data *data)
{
	t_point	end;

	end = last;
	end.x = len * cos(angle) + data->player.pos.x;
	end.y = len * sin(angle) + data->player.pos.y;
	end.car = get_caractere(end, data);
	return (end);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	init(argv[1], &data);
	display_content(&data);
	mlx_hook(data.win, 17, 0, &exiting, &data);
	mlx_hook(data.win, 2, 0, &handle_keypress, &data);
	mlx_loop(data.mlx);
	return (0);
}
