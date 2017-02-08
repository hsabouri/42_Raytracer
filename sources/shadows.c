/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:18:01 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/08 16:00:55 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int				shadows(t_obj *objs, t_ray ray, t_lgt lgt)
{
	t_ray		new;

	lgt.hitpnt = vector_add(ray.org, vector_scale(ray.dir, ray.t));
	new.org = lgt.hitpnt;
	new.dir = normalize_vector(vector_sub(lgt.pos, lgt.hitpnt));
	check_intersections(objs, &new);
	if (new.t > EPSILON)
		return (0);
	return (1);
}
