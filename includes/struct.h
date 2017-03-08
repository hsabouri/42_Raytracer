/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 02:31:15 by ple-lez           #+#    #+#             */
/*   Updated: 2017/03/07 12:20:43 by ple-lez          ###   ########.fr       */
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
	char			*name;
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
	char			*name;
	int				lst;
	t_mat			mat;
	struct s_obj	*chld;
	t_vec4			pos;
	t_vec4			dir;
	t_type			type;
	t_quat			*rot;
	t_quat			*inv;
	double			radius;
	t_vec4			vert[3];
}					t_obj;

/* OpenCL structure */
//
// typedef struct		s_cl
// {
//     cl_device_id		device_id;
//     cl_context			context;
//     cl_command_queue	command_queue;
//     cl_mem				memobj;
//     cl_program			program;
//     cl_kernel			kernel;
//     cl_platform_id		platform_id;
//     cl_uint				ret_num_devices;
//     cl_uint				ret_num_platforms;
//     cl_int				ret;
//     char				str[MEM_SIZE];
//     char				*source_str;
//     size_t				source_size;
// }					t_cl;

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
	void			*img;
	char			*addr;
	unsigned int	n_lgt;
	unsigned int	n_obj;
	unsigned int	n_vrt;
	t_lgt			*lgt;
	t_obj			*objs;
	t_vec4			*vrts;
	t_cam			cam;
	int				bpp;
	int				size;
	int				endian;
//	t_cl			cl;
	int				pr_mesh;
}					t_env;

#endif
