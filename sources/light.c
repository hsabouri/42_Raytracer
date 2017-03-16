/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 20:36:10 by ple-lez           #+#    #+#             */
/*   Updated: 2017/03/16 16:37:25 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_color		apply_coef(t_color col, t_vec4 coef)
{
	t_color	res;

	res.b = (col.b * coef.z);
	res.g = (col.g * coef.y);
	res.r = (col.r * coef.x);
	res.a = 0;
	return (res);
}

double		specular(t_obj obj, t_ray ray, t_lgt lgt)
{
	t_vec4	dir;
	t_vec4	tmp;
	double	spec;

	dir = normalize_vector(vector_sub(lgt.pos, lgt.hitpnt));
	if (obj.rot)
		dir = quat_rot(obj.inv, &dir);
	tmp = vector_scale(lgt.normal, (2.0 * scalar_product(lgt.normal, dir)));
	tmp = vector_sub(dir, tmp);
	if ((spec = scalar_product(tmp, ray.dir)) > 0.0)
		spec = pow(spec, 30.0);
	if (spec > 0.0 && obj.type != PLANE)
		return (spec);
	return (0.0);
}

t_vec4		lambert(t_obj obj, t_ray ray, t_lgt lgt)
{
	t_vec4	tmp;
	t_vec4	dir;
	double	lamb;
	t_vec4	res;

	res = new_vector(lgt.rgb.r, lgt.rgb.g, lgt.rgb.b);
	if (obj.rot)
		ray.dir = quat_rot(obj.inv, &ray.dir);
	tmp = vector_scale(ray.dir, ray.t);
	lgt.hitpnt = vector_add(ray.org, tmp);
	dir = vector_sub(lgt.hitpnt, lgt.pos);
	dir = normalize_vector(dir);
	lgt.normal = get_normal(ray, obj, lgt.hitpnt);
	if (obj.type == CONE)
		lgt.normal.z *= 2;
	lamb = scalar_product(dir, lgt.normal);
	lamb = ft_min_max(lamb, 0.0 , 1.0);
	if (lamb > 0.0)
		lamb += specular(obj, ray, lgt);
	lamb = ft_min_max(lamb, 0.0 , 1.0);
	res = vector_scale(res, lamb);
	return (res);
}
