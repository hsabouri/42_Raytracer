/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procedural.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:58:22 by ple-lez           #+#    #+#             */
/*   Updated: 2017/03/20 11:43:28 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static t_color		bricks(t_obj obj, t_vec4 pos)
{
	int				tx;
	int				ty;
	int				odd;
	int				edge;
	t_color			res;

	tx = (int)((double)10 * pos.x);
	ty = (int)((double)10 * pos.y);
	odd = (tx & 0x01) == (ty & 0x01);
	edge = ((10 * pos.x - tx < 0.1) && odd) || (10 * pos.y - ty < 0.1);
	res = color_scale(obj.mat.rgb, (edge ? 0 : 1));
	return (res);
}

static double		mod(double x)
{
	return (x - floor(x));
}

static t_color		checker(t_obj obj, t_vec4 pos)
{
	double			scl_u;
	double			scl_v;
	double			pattern;
	t_color			res;

	scl_u = 10;
	scl_v = 10;
	pattern = (mod(pos.y * scl_v) < 0.5) ^ (mod(pos.x * scl_u) < 0.5);
	res = color_scale(obj.mat.rgb, pattern);
	return (res);
}

t_color				get_pixel_procedure(t_obj obj, t_vec4 pos)
{
	t_color			res;

	if (obj.mat.texture.type == BRICKS)
		res = bricks(obj, pos);
	else if (obj.mat.texture.type == CHECKER)
		res = checker(obj, pos);
	else if (obj.mat.texture.type == NOISE)
		res = apply_perlin(obj, pos);
	else
		res = (t_color){0, 0, 0, 0};
	return (res);
}
