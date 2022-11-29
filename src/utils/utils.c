/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:48:27 by gborne            #+#    #+#             */
/*   Updated: 2022/11/08 23:31:17 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

char	*multi_char_remove(char *str, char *c, int do_free)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;
	char	*dest;

	i = -1;
	dest = ft_strdup(str);
	if (do_free)
		free(str);
	while (c[++i])
	{
		tmp = malloc((ft_strlen(dest, 0) - c_char(dest, c[i])) * sizeof(char));
		tmp[ft_strlen(dest, '\0')] = '\0';
		j = -1;
		k = -1;
		while (dest[++j])
			if (dest[j] != c[i])
				tmp[++k] = dest[j];
		tmp[++k] = '\0';
		dest = ft_strdup(tmp);
		free(tmp);
	}
	return (dest);
}

char	*char_replace(char *str, char c, char *replace, int do_free)
{
	int		i;
	char	*tmp;
	char	*cpy;

	if (!ft_strchr(str, c))
		return (str);
	cpy = malloc(2 * sizeof(char));
	tmp = malloc((ft_strlen(str, c) + 1) * sizeof(char));
	cpy[1] = '\0';
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			tmp = ft_strjoin(tmp, replace, 1, 0);
		else
		{
			cpy[0] = str[i];
			tmp = ft_strjoin(tmp, cpy, 1, 0);
		}
	}
	if (do_free)
		free(str);
	free(cpy);
	return (tmp);
}

int	count_div(int nb, int ln_base)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		nb /= ln_base;
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int		nb;
	size_t	base_ln;

	base_ln = ft_strlen(base, '\0');
	nb = ft_strlen(base, str[0]) * pow(base_ln, ft_strlen(str, '\0') - 1);
	if (!str[1])
		return (nb);
	return (nb + ft_atoi_base(str + 1, base));
}
