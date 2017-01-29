/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 20:29:56 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/29 18:50:34 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_color			*check_intersections(t_obj *objs, t_ray ray)
{
	double		tmin;
	int			i;
	t_color		*res;

	res = NULL;
	i = 0;
	tmin = EPSILON;
	while (objs[i].type != BACKSLASH)
	{
		if (objs[i].type == SPHERE)
			tmin = intersect_sphere(&ray, objs[i]);
		else if (objs[i].type == PLANE)
			tmin = intersect_sphere(&ray, objs[i]);
		if (tmin > EPSILON)
			res = &objs[i].rgb;
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
			col = check_intersections(objs, ray);
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
