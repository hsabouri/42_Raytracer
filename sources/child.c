/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:44:43 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/21 17:03:34 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

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

static double	return_min(double t, double rayt)
{
	if (t > EPSILON && rayt <= EPSILON)
		return (t);
	else if (rayt > EPSILON && t <= EPSILON)
		return (rayt);
	else
		return (MIN(t, rayt));
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
		return (return_min(t, ray.t));
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
	}
	return (-1.0);
}
