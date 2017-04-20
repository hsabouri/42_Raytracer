/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_lights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:23:37 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/20 16:35:55 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_color					add_colors(t_color c1, t_color c2)
{
	t_color				res;

	res.r = (c1.r + c2.r > 255) ? 255 : c1.r + c2.r;
	res.g = (c1.g + c2.g > 255) ? 255 : c1.g + c2.g;
	res.b = (c1.b + c2.b > 255) ? 255 : c1.b + c2.b;
	res.a = (c1.a + c2.a > 255) ? 255 : c1.a + c2.a;
	return (res);
}

static t_color			add_light(t_obj obj, t_ray ray, t_lgt lgt, double min)
{
	t_vec4				coef;
	double				spec;
	t_color				res;
	t_color				s;
	t_color				rgb;

	rgb = (t_color) {0, 0, 0, 0};
	res = obj.mat.rgb;
	coef = lambert(obj, ray, lgt, min);
	coef = vector_scale(coef, 1.0 / 255);
	coef = vector_cap(coef, 0, 1.0);
	res = apply_coef(res, coef);
	res = add_colors(res, rgb);
	spec = specular(obj, ray, lgt);
	s = color_scale(lgt.rgb, spec);
	res = add_colors(res, s);
	return (res);
}

t_color					sum_lights(t_obj obj, t_ray ray, t_env env)
{
	t_color				res;
	unsigned int		i;
	const unsigned int	n = env.n_lgt - 1;

	i = 0;
	res = (t_color) {0, 0, 0, 0};
	while (i < n)
	{
		if (!env.shadow || shadows(env.objs, ray, env.lgt[i], env.last_id))
			res = add_light(obj, ray, env.lgt[i], env.ambient);
		i++;
	}
	return (res);
}

t_color					lights(t_obj obj, t_ray ray, t_env env, int depth)
{
	t_color				res;
	t_color				add;
	t_ray				sec;

	if (obj.mat.reflect != 1)
		res = sum_lights(obj, ray, env);
	else
		res = (t_color){0, 0, 0, 0};
	if (depth < DEPTH_MAX && obj.mat.reflect > -1.0 && env.render)
	{
		sec = reflect_ray(obj, ray);
		add = handle_reflect(sec, env, depth);
		add = color_scale(add, obj.mat.reflect);
		res = add_colors(res, add);
	}
	if (obj.mat.alpha > EPSILON)
	{
		sec.org = vector_add(ray.org, vector_scale(ray.dir, ray.t));
		sec.dir = ray.dir;
		add = handle_reflect(sec, env, depth);
		add = color_scale(add, obj.mat.alpha);
		res = color_scale(res, 1 - obj.mat.alpha);
		res = add_colors(res, add);
	}
	return (res);
}
