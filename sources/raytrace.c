/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 20:29:56 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/29 21:13:46 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_color			*check_intersections(t_obj *objs, t_ray ray, t_lgt lgt)
{
	double		t;
	double		lamb;
	double		t_tmp;
	int			i;
	t_color		*res;

	res = NULL;
	i = 0;
	t = -1.0;
	t_tmp = -1.0;
	while (objs[i].type != BACKSLASH)
	{
		if (objs[i].type == SPHERE)
			t_tmp = intersect_sphere(&ray, objs[i]);
		else if (objs[i].type == PLANE)
			t_tmp = intersect_sphere(&ray, objs[i]);
		if ((t_tmp < t || t <= EPSILON) && t_tmp > EPSILON)
		{
			t = t_tmp;
			lamb = lambert(objs[i], ray, lgt);
			res = apply_lambert(&objs[i].rgb, lamb);
		}
		i++;
	}
	return (res);
}

int				raytrace(t_cam camera, t_obj *objs, t_env env)
{
	int			x;
	int			y;
	t_ray		ray;
	t_color		*col;

	x = 0;
	while (x < LENGTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			ray = init_ray(&camera, x, y);
			col = check_intersections(objs, ray, env.lgt);
			if (col)
			{
				pixel_put(env, x, y, *col);
			}
			y++;
		}
		x++;
	}
	return (0);
}
