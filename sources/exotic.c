/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exotic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:34:07 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/10 16:55:57 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static double solve_quartic(t_vec4 coef, double e) {return e;}

double		intersect_torus(t_ray ray, t_obj torus)
{
	t_vec4	coef;
	t_vec4	v;
	double	e;
	double	k;
	double	len;

	ray = rotate_ray(ray, torus.inv);
	v = vector_sub(ray.org, torus.pos);
	len = get_vector_len(v);
	len *= len;
	k = 2 * scalar_product(v, ray.dir);
	coef.x = len * len;
	coef.y = 2 * len * k;
	coef.z = 2 * len * (get_vector_len(ray.dir)
			* get_vector_len(ray.dir) + (torus.radius * torus.radius
			- torus.rtube * torus.rtube));
	coef.z += k * k - (4 * torus.radius * torus.radius * (v.x * v.x + v.y * v.y));
	coef.w = 2 * k * (get_vector_len(ray.dir) * get_vector_len(ray.dir)
			+ (torus.radius * torus.radius - torus.rtube * torus.rtube));
	coef.w -= 8 * torus.radius * torus.radius * (v.x * ray.dir.x + v.y * ray.dir.y);
	e = pow((get_vector_len(ray.dir) * get_vector_len(ray.dir)
				+ (torus.radius * torus.radius - torus.rtube * torus.rtube)), 2);
	e -= 4 * torus.radius * torus.radius * (ray.dir.x * ray.dir.x + ray.dir.y * ray.dir.y);
	ray.t = solve_quartic(coef, e);
	return (ray.t);
}
