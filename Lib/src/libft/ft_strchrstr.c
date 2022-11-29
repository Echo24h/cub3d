/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:55:25 by sajansse          #+#    #+#             */
/*   Updated: 2022/11/08 23:10:37 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrstr(char *src, const char *search, size_t len)
{
	unsigned int	i;

	i = -1;
	if (!ft_strlen(src, '\0') || !ft_strlen(search, '\0'))
		return (0);
	if (!src || !search || !len)
		return (0);
	while ((src[++i]))
		if (!ft_strncmp(&src[i], search, len))
			return (&src[i]);
	return (0);
}
