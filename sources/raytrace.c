/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 20:29:56 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/02 12:49:37 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_color			check_intersections(t_obj *objs, t_ray ray, t_lgt lgt)
{
	double			t;
	double			lamb;
	double			t_tmp;
	t_color			res;
	unsigned int	i;

	res = (t_color) {0, 0, 0, 0};
	i = 0;
	t = -1.0;
	t_tmp = -1.0;
	while (objs[i].type != BACKSLASH)
	{
		if (objs[i].rot)
			ray.dir = quat_rot(objs[i].inv, &ray.dir);
		if (objs[i].type == SPHERE)
			t_tmp = intersect_sphere(&ray, objs[i]);
		else if (objs[i].type == PLANE)
			t_tmp = intersect_plane(&ray, objs[i]);
		else if (objs[i].type == CONE)
			t_tmp = intersect_cone(&ray, objs[i]);
		else if (objs[i].type == CYLINDER)
			t_tmp = intersect_cylinder(&ray, objs[i]);
		if ((t_tmp < t || t <= EPSILON) && t_tmp > EPSILON)
		{
			t = t_tmp;
			lamb = lambert(objs[i], ray, lgt);
			res = apply_lambert(objs[i].rgb, lamb);
		}
		if (objs[i].rot)
			ray.dir = quat_rot(objs[i].rot, &ray.dir);
		i++;
	}
	return (res);
}

int				raytrace(t_cam camera, t_obj *objs, t_env env)
{
	unsigned int	x;
	unsigned int	y;
	t_ray			ray;
	t_color			col;

	x = 0;
	while (x < LENGTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			ray = init_ray(&camera, x, y);
			col = check_intersections(objs, ray, env.lgt);
			pixel_put(env, x, y, col);
			y++;
		}
		x++;
	}
	return (0);
}
