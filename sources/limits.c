/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:47:43 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/12 17:33:35 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static double	get_limits(t_obj *obj, double c[2], double oa, double da, double t[2])
{
	double		a0;
	double		a1;
	double		th;

	if (t[0] > t[1])
		ft_fswap(&t[0], &t[1]);
	a0 = oa + t[0] * da;
	a1 = oa + t[1] * da;
	if (a0 < c[0])
	{
		if (a1 < c[0])
			return (-1.0);
		else //Cap
		{
			th = t[0] + (t[1] - t[0]) * (a0 + 1) / (a0 - a1);
			if (th <= EPSILON)
				return (th);
			obj->lmt.dir = (t_vec4){0, -1, 0, 0};
			return (th);
		}
	}
	else if (a0 >= c[0] && a0 <= c[1]) //Cylinder
	{
		obj->lmt.dir = (t_vec4){42, 0, 0, 0};
		return (t[0]);
	}
	else if (a0 > c[1])
	{
		if (a1 > c[1])
			return (-1.0);
		else //Cap
		{
			th = t[0] + (t[1] - t[0]) * (a0 - 1) / (a0 - a1);
			if (th <= EPSILON)
				return (th);
			obj->lmt.dir = (t_vec4){0, 1, 0, 0};
			return (th);
		}
	}
	return (-1.0);
}

double			limit_object(t_obj *obj, t_ray ray, double t1, double t2)
{
	double		res;
	double		tmp;
	double		t[2];
	double		c[2];

	res = -1.0;
	t[0] = t1;
	t[1] = t2;
	obj->lmt.dir.x = 42;
	if (obj->lmt.mode == ROTATION)
		ray = rotate_ray(ray, obj->rot);
	if (obj->lmt.axis.x != 0)
	{
		c[0] = obj->lmt.coef_min.x;
		c[1] = obj->lmt.coef_max.x;
		tmp = get_limits(obj, c, ray.org.x, ray.dir.x, t);
		if (tmp < EPSILON)
			return (-1.0);
		if (res == -1.0 || tmp < res)
			res = tmp;
	}
	if (obj->lmt.axis.y != 0)
	{
		c[0] = obj->lmt.coef_min.y;
		c[1] = obj->lmt.coef_max.y;
		tmp = get_limits(obj, c, ray.org.y, ray.dir.y, t);
		if (tmp < EPSILON)
			return (-1.0);
		if (res == -1.0 || tmp < res)
			res = tmp;
	}
	if (obj->lmt.axis.z != 0)
	{
		c[0] = obj->lmt.coef_min.z;
		c[1] = obj->lmt.coef_max.z;
		tmp = get_limits(obj, c, ray.org.z, ray.dir.z, t);
		if (tmp < EPSILON)
			return (-1.0);
		if (res == -1.0 || tmp < res)
			res = tmp;
	}
	return (res);
}
