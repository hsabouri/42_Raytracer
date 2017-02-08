/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:50:00 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/08 14:58:30 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_lgt			*init_lgts(t_env *env)
{
	t_lgt	*lgts;

	lgts = (t_lgt *)malloc(sizeof(t_lgt) * 3);
	env->n_lgt = 2;

	lgts[0].type = OMNI;
	lgts[0].pos = new_vector(2, 2, -10);
	lgts[0].rgb = (t_color) {255, 0, 0, 0};

	lgts[1].type = OMNI;
	lgts[1].pos = new_vector(0, 10, -5);
	lgts[1].rgb = (t_color) {0, 0, 255, 0};

	lgts[2].type = SPOT;
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
	t_obj		*res;

	axis = new_vector(0, 0, 1);
	res = (t_obj *)malloc(sizeof(t_obj) * 4);
	
	res[0].type = SPHERE;
	res[0].radius = 2;
	res[0].pos = new_vector(0, 0, 0);
	res[0].rot = NULL;
	res[0].inv = NULL;
	res[0].rgb = (t_color){255, 255, 255, 0};

	res[1].type = PLANE;
	res[1].radius = 1;
	res[1].pos = new_vector(1, -1, 0);
	res[1].rot = NULL;
	res[1].inv = NULL;
	res[1].dir = new_vector(0, 1, 0);
	res[1].rgb = (t_color) {255, 155, 155, 0};

	res[2].type = PLANE;
	res[2].radius = 1;
	res[2].pos = new_vector(0, 0, 4);
	res[2].rot = NULL;
	res[2].inv = NULL;
	res[2].dir = new_vector(0, 0, -1);
	res[2].rgb = (t_color) {255, 255, 155, 0};

	res[3].type = BACKSLASH;
	return (res);
}
