/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:58:46 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/16 16:18:44 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double		intersect_cylinder(t_ray ray, t_obj cylinder)
{
	double	a;
	double	b;
	double	c;
	t_vec4	v;

	if (cylinder.rot)
		ray = rotate_ray(ray, cylinder.inv);
	v = vector_sub(ray.org, cylinder.pos);
	a = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z;
	b = 2 * (ray.dir.x * v.x + ray.dir.z * v.z);
	c = (v.x * v.x + v.z * v.z) - cylinder.radius * cylinder.radius;
	ray.t = solve_quadra(a, b, c);
	return (ray.t);
}

double		intersect_cone(t_ray ray, t_obj cone)
{
	double	a;
	double	b;
	double	c;
	t_vec4	v;

	if (cone.rot)
		ray = rotate_ray(ray, cone.inv);
	v = vector_sub(ray.org, cone.pos);
	a = (ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z)
		- (cone.radius * cone.radius * ray.dir.y * ray.dir.y);
	b = 2 * ((ray.dir.x * v.x + ray.dir.z * v.z)
		- (cone.radius * cone.radius * ray.dir.y * v.y));
	c = (v.x * v.x + v.z * v.z)
		- (cone.radius * cone.radius * v.y * v.y);
	ray.t = solve_quadra(a, b, c);
	return (ray.t);
}

double		intersect_sphere(t_ray ray, t_obj sphere)
{
	double	a;
	double	b;
	double	c;
	t_vec4	v;

	if (sphere.rot)
		ray = rotate_ray(ray, sphere.inv);
	v = vector_sub(ray.org, sphere.pos);
	a = scalar_product(ray.dir, ray.dir);
	b = 2 * scalar_product(ray.dir, v);
	c = scalar_product(v, v) - sphere.radius * sphere.radius;
	ray.t = solve_quadra(a, b, c);
	return (ray.t);
}

double		intersect_plane(t_ray ray, t_obj plane)
{
	t_vec4	v;
	double	div;
	double	res;

	if (plane.rot)
		ray = rotate_ray(ray, plane.inv);
	div = scalar_product(plane.dir, ray.dir);
	if (div > EPSILON || div < EPSILON)
	{
		v = vector_sub(plane.pos, ray.org);
		res = scalar_product(v, plane.dir) / div;
		if (res > EPSILON)
		{
			ray.t = res;
			return (res);
		}
		else
			return (-1.0);
	}
	else
		return (-1.0);
}
