/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:44:43 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/12 15:13:00 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#define MIN(a, b) ((a < b) ? a : b)

static t_obj	init_child(t_obj obj)
{
	if (obj.ch_type == CHILD)
	{
		obj.chld = (t_obj *)malloc(sizeof(t_obj) * 2);
		obj.chld[0].name = ft_strdup("child");
		obj.chld[0].rot = new_quat_null();
		obj.chld[0].inv = new_quat_null();
		obj.chld[0].pos = vector_add(obj.pos, (t_vec4){obj.radius, 0, 0, 0});
		obj.chld[0].type = SPHERE;
		obj.chld[0].radius = obj.radius;
		obj.chld[0].mat = obj.mat;
		obj.chld[0].chld = NULL;
		obj.chld[1].type = BACKSLASH;
	}
	else if (obj.ch_type == LIMIT_AR)
	{
		obj.chld = (t_obj *)malloc(sizeof(t_obj) * 3);
		obj.chld[0].name = ft_strdup("max_z");
		obj.chld[0].rot = obj.rot;
		obj.chld[0].inv = obj.inv;
		obj.chld[0].pos = vector_add(obj.pos, (t_vec4){0, 0, -0.5, 0});
		obj.chld[0].type = PLANE;
		obj.chld[0].dir = normalize_vector((t_vec4){0, 0, -1, 0});
		obj.chld[0].mat = obj.mat;
		obj.chld[0].chld = NULL;
		obj.chld[0].ch_type = NOCHILD;
		obj.chld[0].lm_type = MIN;
		obj.chld[1].name = ft_strdup("min_z");
		obj.chld[1].rot = obj.rot;
		obj.chld[1].inv = obj.inv;
		obj.chld[1].pos = vector_add(obj.pos, (t_vec4){0, 0, 0.5, 0});
		obj.chld[1].type = PLANE;
		obj.chld[1].dir = normalize_vector((t_vec4){0, 0, 1, 0});
		obj.chld[1].mat = obj.mat;
		obj.chld[1].chld = NULL;
		obj.chld[1].ch_type = NOCHILD;
		obj.chld[1].lm_type = MAX;
		obj.chld[2].type = BACKSLASH;
		obj.lst = 2;
	}
	return (obj);
}

void			temp_init(t_env *env)
{
	env->objs[0].ch_type = LIMIT_AR;
	env->objs[0] = init_child(env->objs[0]);
}

static int		is_inside(t_obj *obj, t_ray ray, double t)
{
	int			i;
	double		len;
	t_vec4		hit;

	i = 0;
	while (obj->chld[i].type != BACKSLASH)
	{
		ray.t = intersect_plane(ray, obj->chld[i]);
		if ((obj->chld[i].lm_type == MAX && t > ray.t)
			|| (obj->chld[i].lm_type == MIN && t < ray.t))
		{
			hit = vector_add(ray.org, vector_scale(ray.dir, ray.t));
			len = get_vector_len(hit);
			if (len <= obj->radius)
			{
				obj->lst = i;
				return (1); 
			}
			return (0);
		}
		i++;
	}
	obj->lst = i;
	return (1);
}

static double	intersect_pipeline(t_ray ray, t_obj obj)
{
	if (obj.type == SPHERE)
		return (intersect_sphere(ray, obj));
	else if (obj.type == PLANE)
		return (intersect_plane(ray, obj));
	else if (obj.type == CONE)
		return (intersect_cone(ray, obj));
	else
		return (intersect_cylinder(ray, obj));
}

double			intersect_child(t_ray ray, t_obj *obj)
{
	double	t;

	t = intersect_pipeline(ray, *obj);
	if (obj->ch_type == CHILD)
	{
		obj->lst = check_intersections(obj->chld, &ray);
		if (obj->chld[obj->lst].type == BACKSLASH && t <= EPSILON)
			return (-1.0);
		else if (t > EPSILON && ray.t <= EPSILON)
			return (t);
		else if (ray.t > EPSILON && t <=  EPSILON)
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
	else if (obj->ch_type == LIMIT_AR || obj->ch_type == LIMIT_PR)
	{
		if (t <= EPSILON)
			return (-1.0);
		if (is_inside(obj, ray, t))
			return (t);
	}
	return (-1.0);
}
