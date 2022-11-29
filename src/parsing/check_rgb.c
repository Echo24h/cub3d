/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:57:28 by gborne            #+#    #+#             */
/*   Updated: 2022/11/08 23:31:37 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	check_rgb(char **s)
{
	int		i;
	char	**split;

	i = -1;
	*s = ft_substr(ft_strtrim(*s, " \t", 1), 1, ft_strlen(*s, '\0') - 1, 1);
	split = ft_split(*s, ',');
	while (split[++i])
	{
		if (check_rgb_min(split, i) > 0)
			return (1);
	}
	free_tab((void **)split, 0);
	if (i != 3)
		return (ft_printf("Error\nToo less arguments for RGB color !\n"));
	return (0);
}

int	check_rgb_min(char **split, int i)
{
	int	j;

	split[i] = ft_strtrim(split[i], " \t", 1);
	j = -1;
	if (i > 2)
		return (ft_printf("Error\nToo many arguments for RGB color !\n"));
	while (split[i][++j])
	{
		if (!ft_isdigit(split[i][j]) || j > 2)
		{
			free_tab((void **)split, 0);
			return (ft_printf("Error\nWrong RGB!\n", ft_atoi(split[i])));
		}
	}
	if (ft_atoi(split[i]) > 255 || ft_atoi(split[i]) < 0)
	{
		free_tab((void **)split, 0);
		return (ft_printf("Error\nWrong RGB!\n", ft_atoi(split[i])));
	}
	return (0);
}
