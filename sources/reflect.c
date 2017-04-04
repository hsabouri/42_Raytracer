/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:51:30 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/04 16:30:32 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		init_reflect(t_env *env)
{
	env->objs[0].mat.texture = create_xpm_img("textures/earth.xpm", *env);
	env->objs[2].mat.texture = create_xpm_img("textures/wall.xpm", *env);
	env->objs[4].mat.reflect = 1;
	env->objs[3].mat.reflect = 1;
}

t_color		handle_reflect(t_ray ray, t_env env, int depth)
{
	int		id;
	t_color	tmp;
	t_color	res;

	id = check_intersections(env.objs, &ray);
	if (env.objs[id].type == BACKSLASH)
		res = sum_lights(env.objs[env.last_id], ray, env);
	tmp = env.objs[id].mat.rgb;
	if (env.objs[id].mat.texture.type != NOTEX)
		env.objs[id].mat.rgb = get_pixel_color(env.objs[id], ray);
	res = lights(env.objs[id], ray, env, depth + 1);
	return(res);
}
