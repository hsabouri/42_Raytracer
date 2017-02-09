/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:18:01 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/09 10:38:16 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int				shadows(t_obj *objs, t_ray ray, t_lgt lgt)
{
	t_ray		new;
	double		max_dis;

	lgt.hitpnt = vector_add(ray.org, vector_scale(ray.dir, ray.t));
	new.org = lgt.hitpnt;
	new.dir = vector_sub(lgt.pos, lgt.hitpnt);
	max_dis = get_vector_len(new.dir);
	new.dir = normalize_vector(new.dir);
	check_intersections(objs, &new);
	if (new.t > EPSILON && new.t < max_dis)
		return (0);
	return (1);
}
