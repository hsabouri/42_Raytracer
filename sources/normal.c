/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:24:15 by hsabouri          #+#    #+#             */
/*   Updated: 2017/03/02 13:48:36 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vec4		normal_plane(t_ray ray, t_obj obj)
{
	t_vec4 res;

	if (scalar_product(obj.dir, ray.dir) < EPSILON)
		res = vector_scale(obj.dir, -1.0);
	else
		res = obj.dir;
	return (res);
}

t_vec4		normal_polygon(t_obj poly)
{
	t_vec4	ab;
	t_vec4	ac;
	t_vec4	res;

	ab = vector_sub(poly.vert[2], poly.vert[1]);
	ac = vector_sub(poly.vert[0], poly.vert[1]);
	res = cross_product(ab, ac);
	res = normalize_vector(res);
	return (res);
}

t_vec4		normal_cylinder(t_vec4 pos, t_obj obj)
{
	obj.pos.y = pos.y;
	return (normalize_vector(vector_sub(obj.pos, pos)));
}

t_vec4		get_normal(t_ray ray, t_obj obj, t_vec4 pos)
{
	if (obj.type == PLANE)
		return (normal_plane(ray, obj));
	else if (obj.type == CYLINDER)
		return (normal_cylinder(pos, obj));
	else if (obj.type == POLYGON)
	{
		obj.dir = normal_polygon(obj);
		return (normal_plane(ray, obj));
	}
	else if (obj.type == MESH)
		return (get_normal(ray, obj.chld[obj.lst], pos));
	else
		return (normalize_vector(vector_sub(obj.pos, pos)));
}
