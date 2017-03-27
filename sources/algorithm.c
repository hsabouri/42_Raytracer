/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <hsabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 20:29:56 by hsabouri          #+#    #+#             */
/*   Updated: 2017/03/24 15:53:32 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static t_color	pipeline(t_obj *objs, t_ray *ray, t_env env)
{
	t_color			tmp;
	t_color			res;

	res = (t_color) {0, 0, 0, 0};
	env.last_id = check_intersections(objs, ray);
	//env.ui->obj_map = pixel_put(env.ui->obj_map, ray->x, ray->y, *(t_color *)&env.last_id);
	if (objs[env.last_id].type == BACKSLASH)
		return (res);
	tmp = objs[env.last_id].mat.rgb;
	if (objs[env.last_id].mat.texture.type != NOTEX)
		objs[env.last_id].mat.rgb = get_pixel_color(objs[env.last_id], *ray);
	res = lights(objs[env.last_id], *ray, env);
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
		if (objs[i].type == MESH)
			t_tmp = intersect_mesh(*ray, &objs[i]);
		else if (objs[i].type == SPHERE)
			t_tmp = intersect_sphere(*ray, objs[i]);
		else if (objs[i].type == PLANE)
			t_tmp = intersect_plane(*ray, objs[i]);
		else if (objs[i].type == CONE)
			t_tmp = intersect_cone(*ray, objs[i]);
		else if (objs[i].type == CYLINDER)
			t_tmp = intersect_cylinder(*ray, objs[i]);
		else if (objs[i].type == POLYGON)
			t_tmp = intersect_polygon(*ray, objs[i]);
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

int				test_ss_raytrace(t_cam camera, t_obj *objs, t_env env)
{
	unsigned int	x;
	unsigned int	y;
	t_ray			ray;
	t_color			col[4];
	t_color			color;

	x = 0;
	while (x < LENGTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
				ray = init_ray(&camera, x - 0.45, y - 0.45);
				col[0] = pipeline(objs, &ray, env);
				ray = init_ray(&camera, x + 0.45, y - 0.45);
				col[1] = pipeline(objs, &ray, env);
				ray = init_ray(&camera, x - 0.45, y + 0.45);
				col[2] = pipeline(objs, &ray, env);
				ray = init_ray(&camera, x + 0.45, y + 0.45);
				col[3] = pipeline(objs, &ray, env);
				color.r = (col[0].r + col[1].r + col[2].r + col[3].r) / 4;
				color.g = (col[0].g + col[1].g + col[2].g + col[3].g) / 4;
				color.b = (col[0].b + col[1].b + col[2].b + col[3].b) / 4;
				color.a = (col[0].a + col[1].a + col[2].a + col[3].a) / 4;
				env.img = pixel_put(env.img, x, y, color);
				y++;
		}
		x++;
	}
	return (0);
}

int				raytrace(t_cam camera, t_obj *objs, t_env env)
{
	unsigned int	x;
	unsigned int	y;
	t_ray			ray;
	t_color			col;

	x = 0;
	while (x < LENGTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			ray = init_ray(&camera, x, y);
			col = pipeline(objs, &ray, env);
			if (env.filter)
				col = filters(col, env);
			env.img = pixel_put(env.img, x, y, col);
			if (env.redraw == 1)
			{
				x = 0;
				y = 0;
				env.redraw = 0;
			}
			y++;
		}
		x++;
	}
	return (0);
}
