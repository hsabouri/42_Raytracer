/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 02:31:15 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/19 02:14:57 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "defines.h"
# include "../libvec/includes/vector.h"
# include "../libvec/includes/quaternion.h"

/* Ray structure */

typedef struct		s_ray
{
	t_vec4			org;
	t_vec4			dir;
	double			t;
}					t_ray;

/* Camera structure */

typedef struct		s_cam
{
	t_vec4			pos;
	t_quat			*rot;
	t_mode			control;
	double			fov;
}					t_cam;

/* Color structure */

typedef struct		s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_color;

/* Light structure */

typedef struct		s_lgt
{
	t_ltype			type;
	t_vec4			dir;
	t_vec4			pos;
	t_color			rgb;
	t_vec4			normal;
	t_vec4			hitpnt;
}					t_lgt;

/* Material Structures */

typedef struct		s_mat
{
	t_color			rgb;
	t_vec4			coef;
	int				reflect;
	double			refract;
}					t_mat;

/* Object Structures */

typedef struct		s_obj
{
	t_mat			mat;
	t_vec4			pos;
	t_vec4			dir;
	t_vec4			vert[3];
	t_type			type;
	t_quat			*rot;
	t_quat			*inv;
	double			radius;
}					t_obj;

/* Environement structure */

typedef struct		s_env
{
	int				bpp;
	int				size;
	int				endian;
	int				redraw;
	int				shadow;
	int				last_id;
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	unsigned int	n_lgt;
	t_lgt			*lgt;
	t_cam			cam;
	t_obj			*objs;
}					t_env;

#endif
