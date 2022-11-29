/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:47:50 by gborne            #+#    #+#             */
/*   Updated: 2022/11/08 23:31:30 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 53)
		exiting(data);
	else if (keysym >= 123 && keysym <= 126)
		rotate_view(data, keysym);
	else if ((keysym >= 0 && keysym <= 2) || keysym == 13)
		move_player(data, keysym);
	display_content(data);
	return (0);
}

void	free_tab(void **tab, int size)
{
	int	i;

	i = -1;
	if (!size)
		size = INT_MAX;
	while (++i < size && tab[i] && tab)
		free(tab[i]);
	if (tab)
		free(tab);
}

void	destroy_images(t_data *data)
{
	int	i;

	i = -1;
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		if (data->images.floor)
			free(data->images.floor);
		if (data->images.sky)
			free(data->images.sky);
		if (data->images.wall)
			while (++i < 4)
				if (data->images.wall[i])
					free(data->images.wall[i]);
		if (data->images.wall)
			free(data->images.wall);
	}
}

int	exiting(t_data *data)
{
	int	i;

	i = -1;
	if (data->map.map)
	{
		free_tab((void **)data->map.map, 0);
		i = -1;
		while (++i < 4)
		{
			free_tab((void **)data->images.w_sprite[i].color, 0);
			free_tab((void **)data->images.w_sprite[i].ctab, 64);
			free_tab((void **)data->images.w_sprite[i].sprite, 64);
		}
		free(data->images.w_sprite);
	}
	destroy_images(data);
	ft_printf("Exiting...\n");
	exit(0);
}
