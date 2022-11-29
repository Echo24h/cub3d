/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:47:18 by gborne            #+#    #+#             */
/*   Updated: 2022/11/08 23:31:47 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

char	**xpm_read(int fd, char *limite, int size)
{
	char	*tmp;
	char	**color;
	int		len;

	len = ft_strlen(limite, '\0');
	color = malloc(sizeof(char *) * 2);
	color[0] = NULL;
	color[1] = NULL;
	tmp = get_next_line(fd);
	while (tmp && ft_strncmp(tmp, limite, len))
	{
		tmp = ft_substr(tmp, 0, ft_strlen(tmp, '\n') - 1, 1);
		tmp = ft_strtrim(tmp, "\"\n", 1);
		if (size && (int)ft_strlen(tmp, '\0') == (size * 2))
			tmp = remove_extra_space(tmp);
		if (color[0] == NULL)
			color[0] = ft_strdup(tmp);
		else
			color = ft_tabadd(color, tmp, 1);
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	return (color);
}

int	xpm_color(char **color, char c)
{
	int		i;
	int		size;
	char	*hexa;

	if (ft_tablen(color) < 5)
		return (-1);
	size = ft_strlen(color[4], '#');
	i = -1;
	hexa = NULL;
	while (!hexa && color[++i])
	{
		if (color[i][0] == c && color[i][size] == '#')
			hexa = ft_strdup(&color[i][size + 1]);
	}
	if (hexa == NULL)
		return (-1);
	if (!ft_strncmp(hexa, "None", 4))
		return (-2);
	size = ft_atoi_base(hexa, "0123456789ABCDEF");
	free(hexa);
	return (size);
}

t_texture	xpm_to_tab(char *path, t_data *d)
{
	int			fd;
	int			i;
	int			j;
	t_texture	sprite;

	fd = open(path, O_RDONLY);
	sprite.color = xpm_read(fd, "/* pixels */", 0);
	sprite.sprite = xpm_read(fd, "};", 64);
	if (ft_tablen(sprite.sprite) != d->map.f_size)
		sprite.sprite = NULL;
	sprite.ctab = malloc(sizeof(int *) * d->map.f_size);
	i = -1;
	while (++i < d->map.f_size)
		sprite.ctab[i] = malloc(sizeof(int) * d->map.f_size);
	i = -1;
	while (sprite.sprite && ++i < d->map.f_size)
	{
		j = -1;
		while (++j < d->map.f_size)
			sprite.ctab[j][i] = xpm_color(sprite.color, sprite.sprite[i][j]);
		if (sprite.ctab[j - 1][i] == -1)
			break ;
	}
	close(fd);
	return (sprite);
}
