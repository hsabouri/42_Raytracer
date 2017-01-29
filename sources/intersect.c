/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:58:46 by ple-lez           #+#    #+#             */
/*   Updated: 2017/01/29 23:00:47 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double		intersect_sphere(t_ray *ray, t_obj sphere)
{
	double	a;
	double	b;
	double	c;
	t_vec	v;

	v = vector_sub(ray->org, sphere.pos);
	a = scalar_product(ray->dir, ray->dir);
	b = 2 * scalar_product(ray->dir, v);
	c = scalar_product(v, v) - sphere.radius * sphere.radius;
	ray->t = solve_quadra(a, b, c);
	return (ray->t);
}

double		intersect_plane(t_ray *ray, t_obj plane)
{
	t_vec	v;
	double	div;
	double	res;

	div = scalar_product(plane.dir, ray->dir);
	if (div)
	{
		v = vector_sub(plane.pos, ray->org);
		res = scalar_product(v, plane.dir);
		res /= div;
		if (res > EPSILON)
		{
			ray->t = res;
			return (res);
		}
		return (EPSILON);
	}
	return (EPSILON);
}
