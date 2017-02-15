/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:24:15 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/15 14:08:57 by ple-lez          ###   ########.fr       */
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
