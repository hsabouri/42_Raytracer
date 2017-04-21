/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:19:22 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/21 15:56:00 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#define TEX obj.mat.texture

static t_color	get_color_from_uv(t_obj obj, int x, int y)
{
	t_color		res;
	int			p;

	p = (x * (TEX.bpp / 8)) + (y * TEX.size);
	res.b = TEX.addr[p];
	res.g = TEX.addr[p + 1];
	res.r = TEX.addr[p + 2];
	res.a = 0;
	return (res);
}

static t_vec4	get_coord_coef(double fu, double fv)
{
	t_vec4		res;
	double		fracu;
	double		fracv;

	fracu = fu - (int)fu;
	fracv = fv - (int)fv;
	res.x = (1 - fracu) * (1 - fracv);
	res.y = fracu * (1 - fracv);
	res.z = (1 - fracu) * fracv;
	res.w = fracu * fracv;
	return (res);
}

t_color			get_pixel_from_uv(t_obj obj, t_vec4 pos)
{
	t_color		c[4];
	t_vec4		coef;
	t_vec4		vec;
	double		fu;
	double		fv;

	fu = pos.x * TEX.width;
	fv = pos.y * TEX.height;
	vec.x = ((int)fu) % TEX.width;
	vec.y = ((int)fv) % TEX.height;
	vec.z = (int)(vec.x + 1) % TEX.width;
	vec.w = (int)(vec.y + 1) % TEX.height;
	coef = get_coord_coef(fu, fv);
	c[0] = color_scale(get_color_from_uv(obj, vec.x, vec.y), coef.x);
	c[1] = color_scale(get_color_from_uv(obj, vec.z, vec.y), coef.y);
	c[2] = color_scale(get_color_from_uv(obj, vec.x, vec.w), coef.z);
	c[3] = color_scale(get_color_from_uv(obj, vec.z, vec.w), coef.w);
	return (add_colors(add_colors(c[0], c[1]), add_colors(c[2], c[3])));
}

t_color			get_pixel_color(t_obj obj, t_ray ray)
{
	t_color		res;
	t_vec4		hit;
	t_vec4		pos;

	hit = vector_add(ray.org, vector_scale(ray.dir, ray.t));
	pos = (t_vec4) {0, 0, 0, 0};
	if (obj.type == SPHERE)
		pos = get_sphere_pixel(obj, hit);
	else if (obj.type == PLANE)
		pos = get_plane_pixel(obj, hit);
	else if (obj.type == CYLINDER || obj.type == CONE)
		pos = get_cylinder_pixel(obj, hit);
	if (TEX.type == IMAGE)
		res = get_pixel_from_uv(obj, pos);
	else
		res = get_pixel_procedure(obj, pos);
	return (res);
}
