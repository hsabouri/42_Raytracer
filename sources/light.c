/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 20:36:10 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/08 14:43:19 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_color		apply_lambert(t_color col, t_vec coef)
{
	t_color	res;

	res.b = (col.b * coef.z);
	res.g = (col.g * coef.y);
	res.r = (col.r * coef.x);
	res.a = 0;
	return (res);
}

t_vec		lambert(t_obj obj, t_ray ray, t_lgt lgt)
{
	t_vec	tmp;
	t_vec	dir;
	double	lamb;
	t_vec	res;

	res = new_vector(lgt.rgb.r, lgt.rgb.g, lgt.rgb.b);
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
	lamb = scalar_product(dir, lgt.normal);
	if (lamb < 0.05)
		lamb = 0.05;
	if (lamb > 1.0)
		lamb = 1.0;
	res = vector_scale(res, lamb);
	return (res);
}

t_color		lights(t_obj obj, t_ray ray, t_env env, t_color color)
{
	const unsigned int	n_lgt = env.n_lgt;
	unsigned int		i;
	t_vec				coef;
	t_vec				tmp;
	t_color				res;

	coef = new_vector(0, 0, 0);
	res = (t_color) {0, 0, 0, 0};
	i = 0;
	while (i < n_lgt)
	{
		tmp = lambert(obj, ray, env.lgt[i]);
		tmp = vector_scale(tmp, 1.0 / n_lgt);
		coef = vector_add(coef, tmp);
		i++;
	}
	res = apply_lambert(color, coef);
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
