/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 04:02:21 by ple-lez           #+#    #+#             */
/*   Updated: 2017/03/07 11:13:35 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static t_obj	*realloc_mesh(t_obj obj)
{
	int			i;
	int			j;
	t_obj		*res;

	i = 0;
	j = 0;
	while (obj.chld[i].type != BACKSLASH)
		i++;
	res = (t_obj *)malloc(sizeof(t_obj) * (i + 2));
	while (j < i)
	{
		res[j] = obj.chld[j];
		j++;
	}
	res[j + 1].type = BACKSLASH;
	return (res);
}

double			intersect_mesh(t_ray ray, t_obj *obj)
{
	int			i;
	double		t;
	double		t_tmp;

	obj->lst = -1;
	i = 0;
	t = -1.0;
	t_tmp = -1.0;
	while (obj->chld[i].type != BACKSLASH)
	{
		t_tmp = intersect_polygon(ray, obj->chld[i]);
		if ((t_tmp < t || t <= EPSILON) && t_tmp > EPSILON)
		{
			t = t_tmp;
			obj->lst = i;
		}
		i++;
	}
	if (obj->lst == -1)
		obj->lst = i;
	return (t);
}

t_obj			create_mesh(t_color color, char *name)
{
	t_obj		mesh;

	mesh.name = ft_strdup(name);
	mesh.type = MESH;
	mesh.chld = (t_obj *)malloc(sizeof(t_obj));
	mesh.chld[0].type = BACKSLASH;
	mesh.mat.rgb = color;
	mesh.mat.coef = new_vector(1, 1, 1);
	mesh.mat.reflect = 0;
	mesh.mat.refract = EPSILON;
	mesh.rot = NULL;
	mesh.inv = NULL;
	return (mesh);
}

t_obj			add_polygon(t_obj obj, t_obj poly)
{
	int			i;
	t_obj		*newchld;

	i = 0;
	poly.rot = obj.rot;
	poly.inv = obj.inv;
	newchld = realloc_mesh(obj);
	free(obj.chld);
	obj.chld = newchld;
	while (obj.chld[i].type != BACKSLASH)
		i++;
	obj.chld[i - 1] = poly;
	return (obj);
}
