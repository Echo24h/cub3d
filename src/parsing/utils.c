/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:47:28 by gborne            #+#    #+#             */
/*   Updated: 2022/11/08 23:31:52 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	surround(char **map, t_point p, char *set, int border)
{
	size_t	i;
	size_t	x;
	size_t	y;

	x = p.x;
	y = p.y;
	if (border)
	{
		i = 0;
		while (map[i])
			i++;
		if (!y || y == i - 1)
			return (0);
	}
	if (!x && map[y][x] == '0')
		return (1);
	if (ft_strlen(map[y - 1], '\0') < x + 1 || ft_strlen(map[y + 1], 0) < x + 1)
		return (1);
	if (!ft_strchr(set, map[y][x + 1]))
		return (1);
	if (x && !ft_strchr(set, map[y][x - 1]))
		return (1);
	if ((y && !ft_strchr(set, map[y - 1][x])) || !ft_strchr(set, map[y + 1][x]))
		return (1);
	return (0);
}

int	map_error(char **map, int x, int y, int error_type)
{
	int	i;

	if (error_type == 1)
		ft_printf("Error\nInvalid '%c' in line %d :\n\n", map[y][x], y + 1);
	else if (error_type == 2)
		ft_printf("Error\nVoid in line %d isn't properly surround :\n\n", y
			+ 1);
	else if (error_type == 3)
		ft_printf("Error\nFloor in line %d isn't properly surround :\n\n", y
			+ 1);
	i = -1;
	while (++i <= y)
		ft_printf("%s", map[i]);
	i = -1;
	while (++i < x)
		ft_printf(" ");
	ft_printf("^\n");
	return (1);
}

char	*remove_extra_space(char *line)
{
	char	*dest;
	int		i;
	int		j;

	j = -1;
	i = -1;
	dest = malloc((ft_strlen(line, '\0') / 2 + 1) * sizeof(char *));
	while (line[++i])
		if (!(i % 2))
			dest[++j] = line[i];
	dest[++j] = '\0';
	free(line);
	return (dest);
}

int	check_files(t_data *data)
{
	int	i;
	int	fd;

	i = -1;
	while (++i < 4)
	{
		fd = open (data->images.wall[i], O_RDONLY);
		if (fd < 0)
			return (-1);
		close(fd);
	}
	return (0);
}
