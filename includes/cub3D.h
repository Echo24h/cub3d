/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:04:16 by gborne            #+#    #+#             */
/*   Updated: 2022/11/08 23:09:50 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define F_SIZE 64

typedef struct s_obj
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_obj;

typedef struct s_point
{
	double		x;
	double		y;
	int			color;
	int			or;
	int			car;
}				t_point;

typedef struct s_vecteur
{
	t_point		start;
	t_point		end;
}				t_vecteur;

typedef struct s_view
{
	t_vecteur	*view_walls;
	double		angle;
	int			shadow;
	int			fov;
	double		wall_unit;
}				t_view;

typedef struct s_player
{
	t_view		view;
	int			speed;
	double		h;
	double		x_sensi;
	double		y_sensi;
	double		dir;
	t_point		pos;
}				t_player;

typedef struct s_map
{
	char		**map;
	char		*path;
	char		*handle;
	int			f_size;
	int			f_color;
	int			sky_color;
	int			width;
	int			height;
}				t_map;

typedef struct s_texture
{
	char		**sprite;
	char		**color;
	int			**ctab;
}				t_texture;

typedef struct s_img
{
	char		*floor;
	int			floor_inside;
	char		*sky;
	char		**wall;
	t_texture	*w_sprite;
}				t_img;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			s_width;
	int			s_height;
	double		dst_p;
	double		unit;
	t_map		map;
	t_img		images;
	t_obj		obj;
	t_player	player;
}				t_data;

#endif
