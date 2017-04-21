/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:01:03 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/21 17:05:22 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double			solve_quadra(t_obj *obj, t_ray ray, t_vec4 abc)
{
	double		d;
	double		t1;
	double		t2;

	d = (abc.y * abc.y) - (4.0 * abc.x * abc.z);
	if (d < EPSILON)
		return (0);
	else
	{
		d = sqrt(d);
		t1 = (-abc.y - d) / (2.0 * abc.x);
		t2 = (-abc.y + d) / (2.0 * abc.x);
		if (obj->ch_type == LIMIT)
			return (limit_object(obj, ray, t2, t1));
		if (t1 > EPSILON)
		{
			return (t1);
		}
		else if (t2 > EPSILON)
		{
			return (t2);
		}
	}
	return (EPSILON);
}
