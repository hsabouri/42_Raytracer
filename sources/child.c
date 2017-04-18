/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:44:43 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/18 14:01:22 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static t_obj	init_child(t_obj obj, int n_obj)
{
	if (obj.ch_type == CHILD)
	{
		obj.chld = (t_obj *)malloc(sizeof(t_obj) * 2);
		obj.chld[n_obj].name = ft_strdup("child");
		obj.chld[n_obj].rot = new_quat_null();
		obj.chld[n_obj].inv = new_quat_null();
		obj.chld[n_obj].pos = vector_add(obj.pos, (t_vec4){obj.radius, 0, 0, 0});
		obj.chld[n_obj].type = CONE;
		obj.chld[n_obj].radius = obj.radius;
		obj.chld[n_obj].mat = obj.mat;
		obj.chld[n_obj].chld = NULL;
		obj.chld[n_obj + 1].type = BACKSLASH;
	}
	return (obj);
}

void			temp_init(t_env *env, int n_obj)
{
	env->objs[n_obj].rot = new_quat(PI / 3, (t_vec4){0, 0, 1, 0});
	env->objs[n_obj].inv = get_inverse(env->objs[n_obj].rot);
	env->objs[n_obj].ch_type = LIMIT;
	env->objs[n_obj].lmt.mode = ROTATION;
	env->objs[n_obj].lmt.axis = (t_vec4){0, 1, 0, 0};
	env->objs[n_obj].lmt.coef_min = (t_vec4){-0.5, -1, -0.5, 0};
	env->objs[n_obj].lmt.coef_max = (t_vec4){1, 2, 1, 0};
	env->objs[n_obj] = init_child(env->objs[n_obj], n_obj);
}

static double	intersect_pipeline(t_ray ray, t_obj *obj)
{
	if (obj->type == SPHERE)
		return (intersect_sphere(ray, obj));
	else if (obj->type == PLANE)
		return (intersect_plane(ray, obj));
	else if (obj->type == CONE)
		return (intersect_cone(ray, obj));
	else
		return (intersect_cylinder(ray, obj));
}

double			intersect_child(t_ray ray, t_obj *obj)
{
	double	t;

	t = intersect_pipeline(ray, obj);
	if (obj->ch_type == CHILD)
	{
		obj->lst = check_intersections(obj->chld, &ray);
		if (obj->chld[obj->lst].type == BACKSLASH && t <= EPSILON)
			return (-1.0);
		else if (t > EPSILON && ray.t <= EPSILON)
			return (t);
		else if (ray.t > EPSILON && t <= EPSILON)
			return (ray.t);
		else
			return (MIN(t, ray.t));
	}
	else if (obj->ch_type == INVERSE)
	{
		if (t <= EPSILON)
			return (-1.0);
		obj->lst = check_intersections(obj->chld, &ray);
		if (obj->chld[obj->lst].type == BACKSLASH)
			return (t);
		else if (t < ray.t)
			return (t);
		else
			return (-1.0);
	}
	return (-1.0);
}
