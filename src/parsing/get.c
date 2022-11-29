/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:47:05 by gborne            #+#    #+#             */
/*   Updated: 2022/11/08 23:31:44 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	*get_color_list(t_texture sprite, int colone)
{
	int	*tab;
	int	i;

	i = -1;
	tab = malloc(64 * sizeof(int));
	while (++i < 64)
		tab[i] = sprite.color[colone][i];
	return (tab);
}

char	*get_name(char *path)
{
	char	**split;
	char	*name;
	int		i;

	i = -1;
	split = ft_split(path, '/');
	while (split[++i])
	{
		if (!split[i + 1])
			name = ft_strdup(split[i]);
		free(split[i]);
	}
	free(split);
	return (name);
}

int	get_texture(int fd, t_data *data)
{
	char	*line;

	while ((!data->images.sky || !data->images.floor || !data->images.wall[0]
			|| !data->images.wall[1] || !data->images.wall[2]
			|| !data->images.wall[3]) && line)
	{
		line = get_next_line(fd);
		line = ft_strtrim(line, " \t\n", 1);
		if (!line)
			break ;
		if (!ft_strncmp(line, "NO", 2) && !data->images.wall[0])
			data->images.wall[0] = ft_strdup(line + ft_strlen(line, '.'));
		else if (!ft_strncmp(line, "SO", 2) && !data->images.wall[2])
			data->images.wall[2] = ft_strdup(line + ft_strlen(line, '.'));
		else if (!ft_strncmp(line, "WE", 2) && !data->images.wall[3])
			data->images.wall[3] = ft_strdup(line + ft_strlen(line, '.'));
		else if (!ft_strncmp(line, "EA", 2) && !data->images.wall[1])
			data->images.wall[1] = ft_strdup(line + ft_strlen(line, '.'));
		else if (!ft_strncmp(line, "F", 1) && !data->images.floor)
			data->images.floor = (ft_strdup(line));
		else if (!ft_strncmp(line, "C", 1) && !data->images.sky)
			data->images.sky = ft_strdup(line);
		free(line);
	}
	return (check_texture(data));
}

int	get_map(int fd, t_data *data)
{
	char	*line;
	char	**map;

	map = malloc(2 * sizeof(char *));
	map[1] = NULL;
	line = get_next_line(fd);
	if (line)
		map[0] = ft_strdup(line);
	else
		return (1);
	while (line)
	{
		data->map.height++;
		if ((int)ft_strlen(line, '\0') > data->map.width)
			data->map.width = ft_strlen(line, '\0');
		free(line);
		line = get_next_line(fd);
		if (line)
			map = ft_tabadd(map, char_replace(line, '\t', "    ", 1), 1);
	}
	map = ft_tabtrim(map, "\t \n\0", 1);
	data->map.map = map;
	if (check_map(map))
		return (1);
	return (0);
}
