/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 02:31:15 by ple-lez           #+#    #+#             */
/*   Updated: 2017/03/16 17:34:40 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "vector.h"
# include "quaternion.h"

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
	t_quat			rot;
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
	char			*name;
	t_ltype			type;
	t_vec4			dir;
	t_vec4			pos;
	t_color			rgb;
	t_vec4			normal;
	t_vec4			hitpnt;
}					t_lgt;

/* Noise structure */

typedef struct		s_noise
{
	t_ntype			type;
}					t_noise;

/* Image Structure */

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				size;
	int				endian;
	int				width;
	int				height;
}					t_img;

/* Material Structure */

typedef struct		s_mat
{
	t_color			rgb;
	t_vec4			coef;
	t_noise			noise;
	int				reflect;
	double			refract;
	t_img			texture;
}					t_mat;

/* Object Structure */

typedef struct		s_obj
{
	char			*name;
	int				lst;
	t_mat			mat;
	struct s_obj	*chld;
	t_vec4			pos;
	t_vec4			dir;
	t_type			type;
	t_quat			rot;
	t_quat			inv;
	double			radius;
	t_vec4			vert[3];
}					t_obj;


/* Environement structure */
/* Description:
 * n_lgt : light number
 * n_obj : obj number
 * n_vrt : vertices number
 * *lgt : light array
 * *objs : obj array
 * *vrts : vertices array
 */

typedef struct		s_env
{
	int				redraw;
	int				shadow;
	int				supersampling;
	int				last_id;
	void			*mlx;
	void			*win;
	t_img			img;
	unsigned int	n_lgt;
	unsigned int	n_obj;
	unsigned int	n_vrt;
	t_lgt			*lgt;
	t_obj			*objs;
	t_vec4			*vrts;
	t_filt			filter;
	t_cam			cam;
	int				pr_mesh;
}					t_env;

#endif
