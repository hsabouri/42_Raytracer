/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 02:31:15 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/10 18:32:55 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "vector.h"
# include "quaternion.h"

/* Ray structure */

typedef struct		s_ray
{
	int				x;
	int				y;
	t_vec4			org;
	t_vec4			dir;
	double			t;
	t_vec4			env;
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

/* Image Structure */

typedef struct		s_img
{
	t_ttype			type;
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
	double			reflect;
	double			refract;
	double			alpha;
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
	int				shadow;
	int				supersampling;
	int				last_id;
	int				render;
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
	struct s_ui		*ui;
	pthread_t		render_thread;
	int				pr_mesh;
	int				drawing;
	int				redraw;
	int				frame;
	int				width;
	int				height;
}					t_env;

/* UI structures */

typedef struct		s_pix
{
	int		x;
	int		y;
}					t_pix;

typedef struct		s_line
{
	int dx;
	int dy;
	int xinc;
	int yinc;
	int cumul;
	int x;
	int y;
}					t_line;

typedef struct		s_compnt
{
	int				id;
	void			*value;
	t_status		status;
	int				draw_img;
	int				x;
	int				y;
	int				w;
	int				h;
	t_color			bg;
	t_color			bg_hv;
	t_color			color;
	t_img			img;
	struct s_compnt	(*action)(struct s_compnt, t_env *);
	struct s_compnt	(*hover)(struct s_compnt, t_env *);
	struct s_compnt	(*idle)(struct s_compnt, t_env *);
}					t_compnt;

typedef struct		s_ui
{
	t_compnt		*compnts;
	size_t			n_compnts;
	int				mouse_x;
	int				mouse_y;
	int				click;
	int				last_click;
	t_img			lay1;
	t_img			lay2;
	t_img			obj_map;
	int				redraw;
	int				*keystatus;
	int				width;
	t_obj			place;
	int				height;
}					t_ui;

#endif
