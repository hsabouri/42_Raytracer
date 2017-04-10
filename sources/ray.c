/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:37:39 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/10 15:40:52 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_ray		init_ray(t_cam *cam, int x, int y, t_env *env)
{
	t_vec4	v;
	t_ray	ray;

	ray.org = cam->pos;
	ray.x = x;
	ray.y = y;
	v.x = (x + 0.5) / env->width;
	v.y = (y + 0.5) / env->height;
	v.x = (2 * v.x) - 1;
	v.y = 1 - (2 * v.y);
	v.x *= (env->width / (double)env->height) * tan((cam->fov / 2) * PI / 180);
	v.y *= tan((cam->fov / 2) * PI / 180);
	v.z = 1;
	ray.dir = v;
	ray = rotate_ray(ray, cam->rot);
	ray.t = EPSILON;
	ray.tab[0] = 1;
	ray.tab[1] = NOENV;
	ray.tab[2] = NOENV;
	ray.tab[3] = NOENV;
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

t_ray		refract_ray(t_obj obj, t_ray ray)
{
	t_ray		res;
	t_vec4	norm;
	double	teta1;
	double	n;
	double	c1;
	double	c2;
	t_vec4	tmp;
	int	i;

	i = -1;
	tmp = vector_scale(ray.dir, ray.t);
	res.org = vector_add(ray.org, tmp);
	norm = get_normal(ray, obj, res.org);
	teta1 = scalar_product(ray.dir, norm);
	res.tab[0] = ray.tab[0];
	while (ray.tab[++i] != NOENV)
		res.tab[i] = ray.tab[i];
	res.tab[i] = obj.mat.refract;
	n = res.tab[i - 1]/res.tab[i];
	tmp = vector_scale(ray.dir, n);
	c1 = scalar_product(ray.dir, norm);
	c2 = sqrt(1 - pow(n, 2) * (1 - pow(cos(teta1), 2)));
	res.dir = vector_add(tmp, vector_scale(norm, (n * c1 - c2)));
	return (res);
}
