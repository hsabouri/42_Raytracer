/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:51:30 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/05 13:26:46 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static t_color add_light(t_color c1, t_color c2, double rf)
{
	double		inv;

	inv = 1 - rf;
	c1 = color_scale(c1, inv);
	c2 = color_scale(c2, rf);
	return (add_colors(c1, c2));
}

t_color			handle_reflect(t_ray ray, t_env env, int depth)
{
	int			id;
	t_color		own;
	t_color		sec;
	t_color		res;

	sec = (t_color){0, 0, 0, 0};
	id = check_intersections(env.objs, &ray);
	if (env.objs[id].type != BACKSLASH)
	{
		if (env.objs[id].mat.texture.type != NOTEX)
			env.objs[id].mat.rgb = get_pixel_color(env.objs[id], ray);
		sec = lights(env.objs[id], ray, env, depth + 1);
	}
	if (env.objs[env.last_id].mat.texture.type != NOTEX)
		env.objs[env.last_id].mat.rgb = get_pixel_color(env.objs[env.last_id], ray);
	own = sum_lights(env.objs[env.last_id], ray, env);
	res = add_light(own, sec, env.objs[env.last_id].mat.reflect);
	return(res);
}
