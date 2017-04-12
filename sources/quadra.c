/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:01:03 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/12 17:04:39 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double			solve_quadra(t_obj *obj, t_ray ray, double a, double b, double c)
{
	double		d;
	double		t1;
	double		t2;

	d = (b * b) - (4.0 * a * c);
	if (d < EPSILON)
		return (0);
	else
	{
		d = sqrt(d);
		t1 = (-b - d) / (2.0 * a);
		t2 = (-b + d) / (2.0 * a);
		if (obj->ch_type == LIMIT)
			return (limit_object(obj, ray, t2, t1));
		if (t1 > EPSILON) {
			return t1;
		}
		else if (t2 > EPSILON) {
			return t2;
		}
	}
	return (EPSILON);
}
