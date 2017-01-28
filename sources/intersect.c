/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:58:46 by ple-lez           #+#    #+#             */
/*   Updated: 2017/01/28 20:15:56 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_ray	intersect_sphere(t_ray ray, t_obj sphere, t_vec *cross_point)
{
	double a;
	double b;
	double b;

	a = ray.dir.x * ray.dir.x + ray.dir.y * ray.dir.y + ray.dir.z * ray.dir.z;
	b = 2 * (ray.dir.x * (ray.org.x - sphere.pos.x)) +
		(ray.dir.y * (ray.org.y - sphere.pos.y)) +
		(ray.dir.z - (ray.org.z - sphere.pos.z));
	c = (ray.org.x - sphere.pos.x) * (ray.org.x - sphere.pos.x) +
		(ray.org.y - sphere.pos.y) * (ray.org.y - sphere.pos.y) +
		(ray.org.z - sphere.pos.z) * (ray.org.z - sphere.pos.z) -
		sphere.radius * sphere.radius;
	ray.t = solve_quadra(a, b, c);
	cross_point->x = ray.dir.x * ray.t + ray.org.x;
	cross_point->y = ray.dir.y * ray.t + ray.org.y;
	cross_point->z = ray.dir.z * ray.t + ray.org.z;
	return (ray);
}

t_ray	intersect_plane(t_ray ray, t_obj plane, t_vec *cross_point)
{
	double	div;

	div = scalar_product(plane.dir, ray.dir);
	if (div <= EPSILON)
		return (ray)
	ray.t = -(scalar_product(plane.dir, ray.org) + plane.radius) / div;
	cross_point.x = ray.dir.x * ray.t + ray.org.x;
	cross_point.y = ray.dir.y * ray.t + ray.org.y;
	cross_point.z = ray.dir.z * ray.t + ray.org.z;
	return (ray)
}
