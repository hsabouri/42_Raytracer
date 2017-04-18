/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:47:43 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/18 15:52:28 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static double	get_limits(t_obj *obj, double c[2], double t[2], double a[2], t_vec4 v)
{
	double		th;

	if (a[0] < c[0])
	{
		if (a[1] < c[0])
			return (-1.0);
		else
		{
			th = t[0] + (t[1] - t[0]) * (a[0] + 1) / (a[0] - a[1]);
			if (th <= EPSILON)
				return (th);
			obj->lmt.dir = vector_scale(v, -1);;
			return (th);
		}
	}
	else if (a[0] >= c[0] && a[0] <= c[1])
	{
		obj->lmt.dir = (t_vec4){42, 0, 0, 0};
		return (t[0]);
	}
	else if (a[0] > c[1])
	{
		if (a[1] > c[1])
			return (-1.0);
		else
		{
			th = t[0] + (t[1] - t[0]) * (a[0] - 1) / (a[0] - a[1]);
			if (th <= EPSILON)
				return (th);
			obj->lmt.dir = v;
			return (th);
		}
	}
	return (-1.0);
}

static double	check_in(t_obj *obj, t_ray ray, double t[2], char cmp)
{
	double		c[2];
	double		a[2];
	t_vec4		v;

	c[0] = get_component(obj->lmt.coef_min, cmp);
	c[1] = get_component(obj->lmt.coef_max, cmp);
	if (t[0] > t[1])
		ft_fswap(&t[0], &t[1]);
	if (cmp == 'x')
		v = (t_vec4){1, 0, 0, 0};
	if (cmp == 'y')
		v = (t_vec4){1, 0, 0, 0};
	if (cmp == 'z')
		v = (t_vec4){1, 0, 0, 0};
	a[0] = get_component(ray.org, cmp) + t[0] * get_component(ray.dir, cmp);
	a[1] = get_component(ray.org, cmp) + t[1] * get_component(ray.dir, cmp);
	return (get_limits(obj, c, t, a, v));
}

double			limit_object(t_obj *obj, t_ray ray, double t1, double t2)
{
	double		res;
	double		tmp;
	double		t[2];

	res = -1.0;
	t[0] = t1;
	t[1] = t2;
	obj->lmt.dir.x = 42;
	if (obj->lmt.mode == ROTATION)
		ray = rotate_ray(ray, obj->rot);
	if (obj->lmt.axis.x != 0)
	{
		tmp = check_in(obj, ray, t, 'x');
		tmp = (tmp < EPSILON) ? -1.0 : EPSILON;
		res = ((res == -1.0) || (tmp < res)) ? tmp : res;
	}
	if (obj->lmt.axis.y != 0)
	{
		tmp = check_in(obj, ray, t, 'y');
		tmp = (tmp < EPSILON) ? -1.0 : EPSILON;
		res = ((res == -1.0) || (tmp < res)) ? tmp : res;
	}
	if (obj->lmt.axis.z != 0)
	{
		tmp = check_in(obj, ray, t, 'z');
		tmp = (tmp < EPSILON) ? -1.0 : EPSILON;
		res = ((res == -1.0) || (tmp < res)) ? tmp : res;
	}
	return (res);
}
