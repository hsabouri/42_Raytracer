/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:37:39 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/04 15:02:18 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_ray		init_ray(t_cam *cam, int x, int y)
{
	t_vec4	v;
	t_ray	ray;

	ray.org = cam->pos;
	ray.x = x;
	ray.y = y;
	v.x = (x + 0.5) / LENGTH;
	v.y = (y + 0.5) / HEIGHT;
	v.x = (2 * v.x) - 1;
	v.y = 1 - (2 * v.y);
	v.x *= (LENGTH / (double)HEIGHT) * tan((cam->fov / 2) * PI / 180);
	v.y *= tan((cam->fov / 2) * PI / 180);
	v.z = 1;
	ray.dir = v;
	ray = rotate_ray(ray, cam->rot);
	ray.t = EPSILON;
	return (ray);
}

t_ray		rotate_ray(t_ray ray, t_quat rot)
{
	t_ray	res;

	res.dir = quat_rot(rot, ray.dir);
	res.org = quat_rot(rot, ray.org);
	return (res);
}

t_ray		reflect_ray(t_obj obj, t_ray ray)
{
	t_ray	res;
	t_vec4	norm;
	t_vec4	tmp;
	double	coef;

	tmp = vector_scale(ray.dir, ray.t);
	res.org = vector_add(ray.org, tmp);
	norm = get_normal(ray, obj, res.org);
	coef = scalar_product(norm, ray.dir);
	coef *= 2.0;
	tmp = vector_scale(norm, coef);
	res.dir = vector_sub(ray.dir, tmp);
	return (res);
}

t_ray		refract_ray(t_obj obj, t_ray ray, double r)
{
	t_ray	res;
	t_vec4	norm;
	double	coef;
	double	tmp;

	r = 1 / r;
	res.org = vector_scale(ray.dir, ray.t);
	norm = get_normal(ray, obj, res.org);
	coef = scalar_product(norm, ray.dir);
	tmp = sqrt(1 - (r * r * (1 - coef * coef)));
	res.dir = vector_scale(norm, r * coef - tmp);
	res.dir = vector_add(vector_scale(ray.dir, r), res.dir);
	return (res);
}
