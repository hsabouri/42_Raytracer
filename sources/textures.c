/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:19:22 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/10 13:56:49 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#define TEX obj.mat.texture

t_color			get_pixel_from_uv(t_obj obj, t_vec4 pos)
{
	t_color		res;
	int			x;
	int			y;
	int			p;

	x = (int)(pos.x * (double)TEX.width);
	y = (int)(pos.y * (double)TEX.height);
	p = (x * (TEX.bpp / 8)) + (y * TEX.size);
	res.b = TEX.addr[p    ];
	res.g = TEX.addr[p + 1];
	res.r = TEX.addr[p + 2];
	res.a = 0;
	return (res);
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
