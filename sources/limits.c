/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:47:43 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/22 18:27:39 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static double	calc_th(t_obj *obj, t_vec4 coef0, t_vec4 coef1, t_vec4 v)
{
	double		th;

	th = coef0.z + (coef1.z - coef0.z) * (coef0.y + coef0.w);
	th /= (coef0.y - coef1.y);
	obj->lmt.dir = vector_scale(v, -coef0.w);
	return (th);
}

static double	get_limits(t_obj *obj, t_vec4 coef0, t_vec4 coef1, t_vec4 v)
{
	if (coef0.y < coef0.x)
	{
		coef0.w = 1;
		if (coef1.y < coef0.x)
			return (-1.0);
		else
			return (calc_th(obj, coef0, coef1, v));
	}
	else if (coef0.y >= coef0.x && coef0.y <= coef1.x)
	{
		obj->lmt.dir = (t_vec4){42, 0, 0, 0};
		return (coef0.z);
	}
	else if (coef0.y > coef1.x)
	{
		coef0.w = -1;
		if (coef1.y > coef1.x)
			return (-1.0);
		else
			return (calc_th(obj, coef0, coef1, v));
	}
	return (-1.0);
}

static double	check_in(t_obj *obj, t_ray ray, double t[2], char cmp)
{
	t_vec4		coef0;
	t_vec4		coef1;
	t_vec4		v;

	coef0.x = get_component(obj->lmt.coef_min, cmp);
	coef1.x = get_component(obj->lmt.coef_max, cmp);
	if (t[0] > t[1])
		ft_fswap(&t[0], &t[1]);
	if (cmp == 'x')
		v = (t_vec4){1, 0, 0, 0};
	if (cmp == 'y')
		v = (t_vec4){0, 1, 0, 0};
	if (cmp == 'z')
		v = (t_vec4){0, 0, 1, 0};
	coef0.y = get_component(ray.org, cmp) + t[0] * get_component(ray.dir, cmp);
	coef1.y = get_component(ray.org, cmp) + t[1] * get_component(ray.dir, cmp);
	coef0.z = t[0];
	coef1.z = t[1];
	return (get_limits(obj, coef0, coef1, v));
}

static void		return_min(double *res, double *tmp)
{
	*res = (((*res == -1.0) || (*tmp < *res)) ? *tmp : *res);
}

double			limit_object(t_obj *obj, t_ray ray, double t1, double t2)
{
	double		res;
	double		tmp;
	double		t[2];

	res = -1.0;
	t[0] = t1;
	t[1] = t2;
	if (obj->lmt.mode == ROTATION)
		ray = rotate_ray(ray, obj->rot);
	if (obj->lmt.axis.x != 0)
	{
		tmp = check_in(obj, ray, t, 'x');
		return_min(&res, &tmp);
	}
	if (obj->lmt.axis.y != 0)
	{
		tmp = check_in(obj, ray, t, 'y');
		return_min(&res, &tmp);
	}
	if (obj->lmt.axis.z != 0)
	{
		tmp = check_in(obj, ray, t, 'z');
		return_min(&res, &tmp);
	}
	return (res);
}
