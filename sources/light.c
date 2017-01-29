/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 20:36:10 by ple-lez           #+#    #+#             */
/*   Updated: 2017/01/29 23:01:52 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_color		apply_lambert(t_color col, double l)
{
	t_color	res;

	res.r = ((double)col.r * l);
	res.g = ((double)col.g * l);
	res.b = ((double)col.b * l);
	return (res);
}

double		lambert(t_obj obj, t_ray ray, t_lgt lgt)
{
	t_vec	tmp;
	t_vec	dir;
	double	res;

	tmp = vector_scale(ray.dir, ray.t);
	lgt.hitpnt = vector_add(ray.org, tmp);
	dir = vector_sub(lgt.hitpnt, lgt.pos);
	dir = normalize_vector(dir);
	if (obj.type == PLANE)
		lgt.normal = obj.dir;
	else
	{
		tmp = vector_sub(obj.pos, lgt.hitpnt);
		lgt.normal = normalize_vector(tmp);
	}
	res = scalar_product(dir, lgt.normal);
	if (res < 0.1)
		res = 0.1;
	return (res);
}
