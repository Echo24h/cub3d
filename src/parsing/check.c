/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:46:54 by gborne            #+#    #+#             */
/*   Updated: 2022/11/08 23:31:41 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	check_file(int fd, char *path)
{
	if (fd == -1)
		ft_printf("Error\nFile '%s' does not exist !", path);
	else if (ft_strchr(path, '.') == NULL)
		ft_printf("Error\nFile '%s' has no extension !\n", path);
	else if (ft_strncmp(ft_strrchr(path, '.'), ".cub", 4))
		ft_printf("Error\nFile '%s' is not a .cub file !\n", path);
	else if (ft_strlen(ft_strrchr(path, '.'), '\0') != 4)
		ft_printf("Error\nFile '%s' is not a .cub file !\n", path);
	else
		return (0);
	close(fd);
	return (1);
}

int	check_texture(t_data *data)
{
	int	i;

	i = -1;
	if (!data->images.wall[0] || !data->images.wall[1] || !data->images.wall[2]
		|| !data->images.wall[3] || !data->images.sky || !data->images.floor)
		return (ft_printf("Error\nSome walls texture paths arn't set !\n"));
	if (check_files(data) == -1)
		return (ft_printf("Error\nWrong textures !\n"));
	data->images.w_sprite = malloc(sizeof(t_texture) * 4);
	while (++i < 4)
	{
		data->images.w_sprite[i] = xpm_to_tab(data->images.wall[i], data);
		free(data->images.wall[i]);
	}
	free(data->images.wall);
	data->images.wall = NULL;
	if (check_rgb(&data->images.floor))
		return (1);
	if (check_rgb(&data->images.sky))
		return (1);
	return (0);
}

int	check_other(char **map)
{
	int	i;
	int	j;
	int	nb;

	i = -1;
	nb = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSEW", map[i][j]))
				nb++;
			else if (!ft_strchr("01NESW \n", map[i][j]))
				return (map_error(map, j, i, 1));
		}
	}
	if (!nb)
		return (ft_printf("Error\nThere isn't any player !\n"));
	else if (nb > 1)
		return (ft_printf("Error\nMultiplayer isn't implement !\n"));
	else
		return (0);
}

int	check_map(char **map)
{
	t_point	pos;
	char	c;

	if (!map)
		return (ft_printf("Error\nMap is empty !\n"));
	pos.y = 0;
	while (++pos.y < ft_tablen(map) - 1)
	{
		pos.x = -1;
		while (map[(int)pos.y][(int)++pos.x])
		{
			c = map[(int)pos.y][(int)pos.x];
			if (c == ' ' && surround(map, pos, " 1\n \0", 1))
				return (map_error(map, pos.x, pos.y, 2));
			if (c == 48 && surround(map, pos, "01NESW", 0))
				return (map_error(map, pos.x, pos.y, 3));
		}
	}
	if (ft_strdiffstr(map[(int)pos.y], "1\n ") || ft_strdiffstr(map[0], "1\n "))
		return (ft_printf("Error\nTop or Bottom border isn't complete !\n"));
	return (check_other(map));
}
