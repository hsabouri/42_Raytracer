/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 20:29:56 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/15 15:26:05 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static t_color	pipeline(t_obj *objs, t_ray *ray, t_env env)
{
	t_color			res;
	t_obj			obj;

	res = (t_color) {0, 0, 0, 0};
	env.last_id = check_intersections(objs, ray);
	if (obj.type == BACKSLASH)
		return (res);
	res = objs[env.last_id].rgb;
	res = lights(objs[env.last_id], *ray, env, res);
	return (res);
}

int				check_intersections(t_obj *objs, t_ray *ray)
{
	double			t;
	double			t_tmp;
	unsigned int	i;
	int				i_final;

	i = 0;
	i_final = -1;
	t = -1.0;
	t_tmp = -1.0;
	while (objs[i].type != BACKSLASH)
	{
		if (objs[i].type == SPHERE)
			t_tmp = intersect_sphere(*ray, objs[i]);
		else if (objs[i].type == PLANE)
			t_tmp = intersect_plane(*ray, objs[i]);
		else if (objs[i].type == CONE)
			t_tmp = intersect_cone(*ray, objs[i]);
		else if (objs[i].type == CYLINDER)
			t_tmp = intersect_cylinder(*ray, objs[i]);
		if ((t_tmp < t || t <= EPSILON) && t_tmp > EPSILON)
		{
			t = t_tmp;
			i_final = i;
		}
		i++;
	}
	if (i_final == -1)
		i_final = i;
	ray->t = t;
	return (i_final);
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
			col = pipeline(objs, &ray, env);
			pixel_put(env, x, y, col);
			y++;
		}
		x++;
	}
	return (0);
}
