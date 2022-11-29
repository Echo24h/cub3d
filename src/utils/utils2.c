/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:48:33 by gborne            #+#    #+#             */
/*   Updated: 2022/11/08 23:31:14 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

char	*convert_base(int nb, char *base)
{
	char	*str;
	int		i;
	int		lng;

	lng = ft_strlen(base, '\0');
	str = malloc(count_div(nb, lng) + 1 * sizeof(char *));
	str[count_div(nb, lng)] = '\0';
	i = count_div(nb, lng);
	while (--i >= 0)
	{
		str[i] = base[nb % lng];
		nb /= lng;
	}
	return (str);
}

int	rgb_to_int(char *str)
{
	int		r;
	int		g;
	int		b;
	char	**split;

	split = ft_split(str, ',');
	r = ft_atoi(split[0]);
	free(split[0]);
	g = ft_atoi(split[1]);
	free(split[1]);
	b = ft_atoi(split[2]);
	free(split[2]);
	free(split);
	return (r << 16 | g << 8 | b);
}

char	**ft_tabdup(char **tab, int do_free)
{
	char	**new;
	int		i;

	i = -1;
	new = malloc((ft_tablen(tab) + 1) * sizeof(char *));
	while (tab[++i])
	{
		new[i] = ft_strdup(tab[i]);
		if (do_free)
			free(tab[i]);
	}
	new[i] = NULL;
	if (do_free)
		free(tab);
	return (new);
}

int	c_char(char *str, char c)
{
	int	i;
	int	nb;

	nb = 0;
	i = -1;
	while (str[++i])
		if (str[i] == c)
			nb++;
	return (nb);
}

t_point	choose_point(t_point *pos, t_data *data, t_point off)
{
	t_point	p;

	if (get_ln(data->player.pos, pos[1]) < get_ln(data->player.pos, pos[0]))
	{
		p = newpoint(pos[1].x + off.x, pos[1].y, pos[1].car, pos[1].or);
		free(pos);
		return (p);
	}
	p = newpoint(pos[0].x, pos[0].y + off.y, pos[0].car, pos[0].or);
	free(pos);
	return (p);
}
