/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polygon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 02:47:21 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/19 03:42:53 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static double	inside_out(t_ray ray, t_obj poly)
{
	t_vec4		c;
	t_vec4		hit;
	t_vec4		edge0;
	t_vec4		edge1;
	t_vec4		edge2;

	hit = vector_add(ray.org, vector_scale(ray.dir, ray.t));
	edge0 = vector_sub(poly.vert[1], poly.vert[0]);
	c = cross_product(edge0, vector_sub(hit, poly.vert[0]));
	if (scalar_product(poly.dir, c) < 0)
		return (-1.0);
	edge1 = vector_sub(poly.vert[2], poly.vert[1]);
	c = cross_product(edge1, vector_sub(hit, poly.vert[1]));
	if (scalar_product(poly.dir, c) < 0)
		return (-1.0);
	edge2 = vector_sub(poly.vert[0], poly.vert[2]);
	c = cross_product(edge2, vector_sub(hit, poly.vert[2]));
	if (scalar_product(poly.dir, c) < 0)
		return (-1.0);
	return (ray.t);
}

double			intersect_polygon(t_ray ray, t_obj poly)
{
	t_vec4		ab;
	t_vec4		ac;
	double		d;
	double		len;

	ab = vector_sub(poly.vert[1], poly.vert[0]);
	ac = vector_sub(poly.vert[2], poly.vert[0]);
	poly.dir = normal_polygon(poly);
	d = scalar_product(poly.dir, poly.vert[0]);
	ray.t = -(scalar_product(ray.org, poly.dir) + d);
	ray.t /= scalar_product(ray.dir, poly.dir);
	if (ray.t < 0)
		return (-1.0);
	ray.t = inside_out(ray, poly);
	return (ray.t);
}
