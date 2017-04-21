/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <hsabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 20:29:56 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/21 15:56:50 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static double	if_forest(t_obj *objs, t_ray *ray, double t_tmp, unsigned int i)
{
	if (objs[i].type == MESH)
		t_tmp = intersect_mesh(*ray, &objs[i]);
	else if (objs[i].ch_type != NOCHILD && objs[i].ch_type != LIMIT)
		t_tmp = intersect_child(*ray, &objs[i]);
	else if (objs[i].type == SPHERE)
		t_tmp = intersect_sphere(*ray, &objs[i]);
	else if (objs[i].type == PLANE)
		t_tmp = intersect_plane(*ray, &objs[i]);
	else if (objs[i].type == CONE)
		t_tmp = intersect_cone(*ray, &objs[i]);
	else if (objs[i].type == CYLINDER)
		t_tmp = intersect_cylinder(*ray, &objs[i]);
	else if (objs[i].type == POLYGON)
		t_tmp = intersect_polygon(*ray, objs[i]);
	return (t_tmp);
}

static t_color	pipeline(t_obj *objs, t_ray *ray, t_env env)
{
	t_color			tmp;
	t_color			res;

	res = (t_color) {0, 0, 0, 0};
	env.last_id = check_intersections(objs, ray);
	if (objs[env.last_id].type == BACKSLASH)
		return (get_skybox(*ray, env));
	tmp = objs[env.last_id].mat.rgb;
	if (objs[env.last_id].mat.texture.type != NOTEX && env.render)
		objs[env.last_id].mat.rgb = get_pixel_color(objs[env.last_id], *ray);
	res = lights(objs[env.last_id], *ray, env, 0);
	objs[env.last_id].mat.rgb = tmp;
	return (res);
}

int				check_intersections(t_obj *objs, t_ray *ray)
{
	double			t;
	double			t_tmp;
	unsigned int	i;
	int				i_final;

	i = 0;
	i_final = -1;
	t = -1.0;
	t_tmp = -1.0;
	while (objs[i].type != BACKSLASH)
	{
		t_tmp = if_forest(objs, ray, t_tmp, i);
		if ((t_tmp < t || t <= EPSILON) && t_tmp > EPSILON)
		{
			t = t_tmp;
			i_final = i;
		}
		i++;
	}
	if (i_final == -1)
		i_final = i;
	ray->t = t;
	return (i_final);
}

static t_img	raytrace_2(t_cam camera, t_env *env, int x, int y)
{
	t_ray		ray;
	t_color		col;
	t_obj		*objs;

	objs = env->objs;
	ray = init_ray(&camera, x, y, env);
	col = pipeline(objs, &ray, *env);
	if (env->filter && env->render)
		col = filters(col, *env);
	return (pixel_put(env->img, x, y, col));
}

int				raytrace(t_cam camera, t_env *env)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	while (i < 16)
	{
		y = i / 4;
		while (y < env->height)
		{
			x = i % 4;
			while (x < env->width)
			{
				env->img = raytrace_2(camera, env, x, y);
				x += 4;
				if (env->redraw == 1)
					return (env->drawing = 0);
			}
			y += 4;
		}
		i++;
	}
	return (0);
}
