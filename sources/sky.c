/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:48:40 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/11 15:34:59 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_obj		init_skybox(t_env env)
{
	t_obj	res;

	res.rot = new_quat_null();
	res.inv = new_quat_null();
	res.type = BACKSLASH;
	res.pos = env.cam.pos;
	res.radius = 200;
	res.mat.texture = create_xpm_img("textures/mountain.xpm", env);
	return (res);
}

t_color		get_skybox(t_ray ray, t_env env)
{
	t_color	res;
	t_vec4	pos;
	t_vec4	hit;

	ray.t = intersect_sphere(ray, env.objs[env.n_obj - 1]);
	hit = vector_add(ray.org, vector_scale(ray.dir, ray.t));
	pos = get_sphere_pixel(env.objs[env.n_obj - 1], hit);
	res = get_pixel_from_uv(env.objs[env.n_obj - 1], pos);
	return (res);
}
