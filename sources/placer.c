/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:43:42 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/10 15:52:10 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static t_obj		*add_object(t_env env, t_obj obj)
{
	t_obj			*res;
	unsigned int	i;

	i = 0;
	res = (t_obj *)malloc(sizeof(t_obj) * env.n_obj + 1);
	while (i < env.n_obj - 1)
	{
		res[i] = env.objs[i];
		i++;
	}
	res[i] = obj;
	res[i + 1] = init_skybox(env);
	free(env.objs);
	env.n_obj++;
	return (res);
}

int				place_obj(double x, double y, t_env env, t_obj obj)
{
	int			id;
	t_ray		ray;

	ray = init_ray(&env.cam, x, y, &env);
	id = check_intersections(env.objs, &ray);
	if (env.objs[id].type == BACKSLASH)
		return (0);
	obj.pos = vector_add(ray.org, vector_scale(ray.dir, ray.t));
	env.objs = add_object(env, obj);
	return (1);
}
