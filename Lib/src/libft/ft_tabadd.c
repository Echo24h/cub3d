/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:55:25 by sajansse          #+#    #+#             */
/*   Updated: 2022/11/08 23:10:52 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabadd(char **tab, char *to_add, int do_free)
{
	char	**tmp;
	int		i;

	i = -1;
	while (tab[++i])
		;
	tmp = malloc ((i + 2) * sizeof (char *));
	i = -1;
	while (tab[++i])
	{
		tmp[i] = ft_strdup(tab[i]);
		if (do_free && tab[i])
			free (tab[i]);
	}
	tmp[i] = ft_strdup(to_add);
	if (do_free)
		free (tab);
	tmp[i + 1] = NULL;
	return (tmp);
}
