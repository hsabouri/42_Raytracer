/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:50:00 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/06 01:31:09 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

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
	env.lgt.pos = (t_vec) {2, 2, -10, 1};
	env.redraw = 1;

	return (env);
}

t_obj			*init_objs()
{
	t_vec		axis;
	t_obj		*res;

	axis = new_vector(0, 0, 1);
	res = (t_obj *)malloc(sizeof(t_obj) * 3);
	
	res[0].type = SPHERE;
	res[0].radius = 2;
	res[0].pos = new_vector(0, 0, 0);
	res[0].rot = NULL;
	res[0].inv = NULL;
	res[0].rgb = (t_color){255, 255, 255, 0};

	res[1].type = PLANE;
	res[1].radius = 2;
	res[1].pos = new_vector(1, -1, 0);
	res[1].rot = NULL;
	res[1].inv = NULL;
	res[1].dir = new_vector(0, 1, 0);
	res[1].rgb = (t_color) {255, 155, 155, 0};

	res[2].type = BACKSLASH;
	return (res);
}
