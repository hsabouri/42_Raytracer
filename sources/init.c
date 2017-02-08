/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:50:00 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/08 16:18:27 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_lgt			*init_lgts(t_env *env)
{
	t_lgt	*lgts;

	lgts = (t_lgt *)malloc(sizeof(t_lgt) * 5);
	env->n_lgt = 4;

	lgts[0].type = OMNI;
	lgts[0].pos = new_vector(10, 5, -10);
	lgts[0].rgb = (t_color) {255, 0, 0, 0};

	lgts[1].type = OMNI;
	lgts[1].pos = new_vector(-10, 5, -10);
	lgts[1].rgb = (t_color) {0, 0, 255, 0};

	lgts[2].type = OMNI;
	lgts[2].pos = new_vector(-3, 5, -10);
	lgts[2].rgb = (t_color) {0, 255, 255, 0};
	
	lgts[4].type = SPOT;
	
	lgts[3].type = OMNI;
	lgts[3].pos = new_vector(3, 5, -10);
	lgts[3].rgb = (t_color) {0, 255, 0, 0};
	return (lgts);
}

t_ray			init_ray(t_cam *cam, int x, int y)
{
	t_vec	v;
	t_ray	ray;

	ray.org = cam->pos;
	v.x = (x + 0.5) / LENGTH;
	v.y = (y + 0.5) / HEIGHT;
	v.x = (2 * v.x) - 1;
	v.y = 1 - (2 * v.y);
	v.x *= (LENGTH / (double)HEIGHT) * tan((cam->fov / 2) * PI / 180);
	v.y *= tan((cam->fov / 2) * PI / 180);
	v.z = 1;
	ray.dir = v;
	if (cam->rot)
		ray.dir = quat_rot(cam->rot, &ray.dir);
	ray.t = EPSILON;
	return (ray);
}

t_env 			init_env(void)
{
	t_env env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, LENGTH, HEIGHT, "RT");
	env.lgt = init_lgts(&env);
	env.redraw = 1;

	return (env);
}

t_obj			*init_objs(void)
{
	t_vec		axis;
	t_quat		*quat;
	t_quat		*inv;
	t_obj		*res;

	axis = new_vector(0, 0, 1);
	quat = new_quat(PI / 2, axis);
	inv = get_inverse(quat);
	res = (t_obj *)malloc(sizeof(t_obj) * 5);
	
	res[0].type = SPHERE;
	res[0].radius = 2;
	res[0].pos = new_vector(4, 0, 0);
	res[0].rot = NULL;
	res[0].inv = NULL;
	res[0].rgb = (t_color){255, 190, 190, 0};

	res[1].type = PLANE;
	res[1].radius = 1;
	res[1].pos = new_vector(1, -1, 0);
	res[1].rot = NULL;
	res[1].inv = NULL;
	res[1].dir = new_vector(0, 1, 0);
	res[1].rgb = (t_color) {255, 255, 255, 0};

	res[2].type = SPHERE;
	res[2].radius = 2;
	res[2].pos = new_vector(-4, 0, 0);
	res[2].rot = NULL;
	res[2].inv = NULL;
	res[2].rgb = (t_color){190, 190, 255, 0};
	
	res[3].type = CYLINDER;
	res[3].radius = 2;
	res[3].rot = NULL;
	res[3].inv = NULL;
	res[3].pos = new_vector(0, 0, 0);
	res[3].rgb = (t_color){190, 255, 190, 0};
	
	res[4].type = BACKSLASH;
	return (res);
}
