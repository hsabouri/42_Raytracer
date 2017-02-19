/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:24:15 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/19 00:40:21 by ple-lez          ###   ########.fr       */
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

t_vec4		get_normal(t_ray ray, t_obj obj, t_vec4 pos)
{
	if (obj.type == PLANE)
		return (normal_plane(ray, obj));
	else
		return (normalize_vector(vector_sub(obj.pos, pos)));
}
