/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:51:30 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/10 17:28:48 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_color			handle_reflect(t_ray ray, t_env env, int depth)
{
	int			id;
	t_color		res;
	t_color		tmp;

	id = check_intersections(env.objs, &ray);
	res = (t_color){0, 0, 0, 0};
	if (env.objs[id].type != BACKSLASH)
	{
		tmp = env.objs[id].mat.rgb;
		if (env.objs[id].mat.texture.type != NOTEX)
			env.objs[id].mat.rgb = get_pixel_color(env.objs[id], ray);
		res = lights(env.objs[id], ray, env, depth + 1);
		env.objs[id].mat.rgb = tmp;
	}
	else
		res = get_skybox(ray, env);
	return (res);
}
