/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:43:42 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/12 17:48:28 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static t_obj		*add_object(t_env *env, t_obj obj)
{
	t_obj			*res;
	unsigned int	i;

	i = 0;
	res = (t_obj *)ft_malloc(sizeof(t_obj) * (env->n_obj + 2), CLEAN);
	while (i < env->n_obj - 1)
	{
		res[i] = env->objs[i];
		i++;
	}
	res[i] = obj;
	res[i + 1] = init_skybox(*env);
	ft_free(env->objs);
	env->objs = res;
	env->n_obj++;
	env->redraw = 1;
	return (res);
}

static t_obj		*del_object(t_env *env, unsigned int id)
{
	t_obj			*res;
	unsigned int	i;
	unsigned int	adding;

	i = 0;
	adding = 0;
	res = (t_obj *)ft_malloc(sizeof(t_obj) * (env->n_obj), CLEAN);
	while (i + adding < env->n_obj)
	{
		if (i == id)
			adding = 1;
		res[i] = env->objs[i + adding];
		i++;
	}
	res[i] = init_skybox(*env);
	ft_free(env->objs);
	env->objs = res;
	env->n_obj--;
	env->redraw = 1;
	return (res);
}

int					place_obj(int x, int y, t_env *env, t_obj obj)
{
	unsigned int	id;
	t_ray			ray;

	ray = init_ray(&env->cam, x, y, env);
	id = check_intersections(env->objs, &ray);
	if (env->ui->delete == 1)
	{
		del_object(env, id);
		env->ui->delete = 0;
		return (0);
	}
	if (env->objs[id].type == BACKSLASH)
		return (0);
	obj.pos = vector_add(ray.org, vector_scale(ray.dir, ray.t));
	obj.mat.rgb = env->ui->color;
	env->objs = add_object(env, obj);
	return (0);
}

int					select_obj(int x, int y, t_env *env)
{
	t_ray		ray;

	ray = init_ray(&env->cam, x, y, env);
	return (check_intersections(env->objs, &ray));
}
