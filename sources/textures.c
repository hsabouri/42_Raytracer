/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:19:22 by ple-lez           #+#    #+#             */
/*   Updated: 2017/03/16 18:14:34 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#define TEX obj.mat.texture

static t_color	get_sphere_pixel(t_obj obj, t_vec4 vec)
{
	int			pos;
	double		u;
	double		v;
	t_color		res;

	u = 0.5 + atan2(vec.z, vec.x) / (2 * PI);
	v = 0.5 - asin(vec.y) / PI;
	pos = (u * TEX.width) * TEX.bpp;
	pos += (v * TEX.height) * TEX.size;
	res.r = TEX.addr[pos];
	res.g = TEX.addr[pos + 1];
	res.b = TEX.addr[pos + 2];
	return (res);
}

t_color			get_pixel_color(t_obj obj, t_ray ray)
{
	t_color		res;
	t_vec4		hit;

	hit = vector_add(ray.org, vector_scale(ray.dir, ray.t));
	hit = normalize_vector(hit);
	if (obj.type == SPHERE)
		res = get_sphere_pixel(obj, hit);
	else
		res = (t_color) {0, 0, 0, 0};
	return (res);
}
