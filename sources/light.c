/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 20:36:10 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/07 16:00:10 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_color		apply_lambert(t_color col, double l)
{
	t_color	res;

	res.b = (col.b * l);
	res.g = (col.g * l);
	res.r = (col.r * l);
	res.a = 0;
	return (res);
}

double		lambert(t_obj obj, t_ray ray, t_lgt lgt)
{
	t_vec	tmp;
	t_vec	dir;
	double	res;

	if (obj.rot)
		ray.dir = quat_rot(obj.rot, &ray.dir);
	tmp = vector_scale(ray.dir, ray.t);
	lgt.hitpnt = vector_add(ray.org, tmp);
	dir = vector_sub(lgt.hitpnt, lgt.pos);
	dir = normalize_vector(dir);
	if (obj.type == PLANE)
		lgt.normal = normal_plane(ray, obj);
	else
	{
		tmp = vector_sub(obj.pos, lgt.hitpnt);
		lgt.normal = normalize_vector(tmp);
	}
	if (obj.type == CONE)
		lgt.normal.z *= 2;
	res = scalar_product(dir, lgt.normal);
	if (res < 0.05)
		res = 0.05;
	if (res > 1.0)
		res = 1.0;
	return (res);
}

t_color		shadows(t_obj *objs, t_ray ray, t_lgt lgt, t_color color)
{
	t_ray	new;
	t_color	res;

	lgt.hitpnt = vector_add(ray.org, vector_scale(ray.dir, ray.t));
	new.org = lgt.hitpnt;
	new.dir = normalize_vector(vector_sub(lgt.pos, lgt.hitpnt));
	check_intersections(objs, &new);
	if (new.t > EPSILON)
		res = (t_color) {0, 0, 0, 0};
	else
		res = color;
	return (res);
}
