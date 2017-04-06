/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:24:46 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/06 14:25:52 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static t_vec4	get_in_bounds(t_vec4 pos)
{
	if (pos.x > 1.0) {
		while (pos.x > 1.0)
			pos.x -= 1.0;
	}
	else if (pos.x < 0.0) {
		while (pos.x < 0.0)
			pos.x += 1.0;
	}
	if (pos.y > 1.0) {
		while (pos.y > 1.0)
			pos.y -= 1.0;
	}
	else if (pos.y < 0.0) {
		while (pos.y < 0.0)
			pos.y += 1.0;
	}
	return (pos);
}

t_vec4			get_sphere_pixel(t_obj obj, t_vec4 hit)
{
	double		u;
	double		v;
	t_vec4		nrm;
	t_vec4		pos;

	nrm = normalize_vector(vector_sub(hit, obj.pos));
	u = 0.5 + atan2(nrm.z, nrm.x) / (2 * PI);
	v = 0.5 - asin(nrm.y) / PI;
	pos.x = u;
	pos.y = v;
	pos.w = 1;
	return (pos);
}

t_vec4			get_plane_pixel(t_obj obj, t_vec4 hit)
{
	double		u;
	double		v;
	t_vec4		ua;
	t_vec4		va;
	t_vec4		pos;

	ua = new_vector(obj.dir.y, obj.dir.z, -obj.dir.x);
	va = cross_product(ua, obj.dir);
	u = scalar_product(hit, ua);
	v = scalar_product(hit, va);
	pos.x = u;
	pos.y = v;
	pos.w = 1;
	pos = get_in_bounds(pos);
	return (pos);
}

t_vec4			get_cylinder_pixel(t_obj obj, t_vec4 hit)
{
	double		r;
	double		t;
	double		u;
	double		v;
	t_vec4		pos;

	pos.y = hit.y;
	hit = normal_cylinder(hit, obj);
	hit.y = pos.y;
	r = sqrt((hit.x * hit.x) + (hit.z * hit.z));
	t = atan2(hit.z, hit.x);
	u = t;
	v = hit.y;
	pos.x = u;
	pos.y = v;
	pos.w = 1;
	pos = get_in_bounds(pos);
	return (pos);
}
