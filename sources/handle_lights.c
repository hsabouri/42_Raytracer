/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_lights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:23:37 by ple-lez           #+#    #+#             */
/*   Updated: 2017/03/16 16:22:15 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static t_color			add_colors(t_color c1, t_color c2)
{
	t_color				res;

	res.r = (c1.r + c2.r > 255) ? 255 : c1.r + c2.r;
	res.g = (c1.g + c2.g > 255) ? 255 : c1.g + c2.g;
	res.b = (c1.b + c2.b > 255) ? 255 : c1.b + c2.b;
	res.a = (c1.a + c2.a > 255) ? 255 : c1.a + c2.a;
	return (res);
}

static t_color			add_light(t_obj obj, t_ray ray, t_lgt lgt, t_color rgb)
{
	t_vec4				coef;
	t_color				res;

	res = obj.mat.rgb;
	coef = lambert(obj, ray, lgt);
	coef = vector_scale(coef, 1.0 / 255);
	coef = vector_cap(coef, 0, 1.0);
	res = apply_coef(res, coef);
	res = add_colors(res, rgb);
	return (res);
}

t_color					lights(t_obj obj, t_ray ray, t_env env)
{
	const unsigned int	n_lgt = env.n_lgt - 1;
	unsigned int		i;
	t_color				res;

	res = (t_color) {0, 0, 0, 0};
	i = 0;
	while (i < n_lgt)
	{
		if (!env.shadow || shadows(env.objs, ray, env.lgt[i], env.last_id))
			res = add_light(obj, ray, env.lgt[i], res);
		i++;
	}
	return (res);
}
