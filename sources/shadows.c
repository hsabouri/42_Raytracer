/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:18:01 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/15 15:27:32 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static double	check_other_intersect(t_obj *objs, t_ray ray, int id)
{
	double		t;
	double		tmp;
	int 		i;

	i = 0;
	t = EPSILON;
	tmp = -1.0;
	while (objs[i].type != BACKSLASH)
	{
		if (i != id)
		{
			if (objs[i].type == SPHERE)
				tmp = intersect_sphere(ray, objs[i]);
			else if (objs[i].type == PLANE)
				tmp = intersect_plane(ray, objs[i]);
			else if (objs[i].type == CONE)
				tmp = intersect_cone(ray, objs[i]);
			else if (objs[i].type == CYLINDER)
				tmp = intersect_cylinder(ray, objs[i]);
			if ((tmp < t || t <= EPSILON) && tmp > EPSILON)
			{
				t = tmp;
				break;
			}
		}
		i++;
	}
	return t;
}

int				shadows(t_obj *objs, t_ray ray, t_lgt lgt, int id)
{
	t_ray		new;
	double		t;
	double		max_dis;

	lgt.hitpnt = vector_add(ray.org, vector_scale(ray.dir, ray.t));
	new.org = lgt.hitpnt;
	new.dir = vector_sub(lgt.pos, lgt.hitpnt);
	max_dis = get_vector_len(new.dir);
	new.dir = normalize_vector(new.dir);
	t = check_other_intersect(objs, new, id);
	if (t > EPSILON && t < max_dis)
		return (0);
	return (1);
}
