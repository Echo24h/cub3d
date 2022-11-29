/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:07:52 by gborne            #+#    #+#             */
/*   Updated: 2022/11/08 23:09:04 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRA_H
# define EXTRA_H

# include "./cub3D.h"

//EXITING.C
int		exiting(t_data *data);

//SCENE/PLAYER.C
int		move_player(t_data *d, int key);
void	rotate_view(t_data *data, int key);

//HANDLE.C
int		handle_keypress(int keysym, t_data *data);
void	free_tab(void **tab, int size);

//EXTRA.H
int		grid_comp(t_point src, t_point to_check, t_data *data);
char	get_caractere(t_point point, t_data *data);
t_point	choose_point(t_point *pos, t_data *data, t_point off);

#endif