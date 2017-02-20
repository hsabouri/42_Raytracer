/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:30:05 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/19 11:43:11 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <obj.h>

static t_obj *create_obj(t_type type, char *name, t_obj **objects, size_t *n_obj)
{
	t_obj			*new;
	const size_t	c_n_obj = *n_obj;
	size_t			i;

	new = (t_obj *)malloc(sizeof(t_obj) * c_n_obj + 1);
	i = 0;
	while (i < c_n_obj)
	{
		ft_memmove(new + i, *objects + i, sizeof(t_obj));
		i++;
	}
	new[c_n_obj].name = ft_strtrim(name);
	new[c_n_obj].type = type;
	if (*objects != NULL)
		free(*objects);
	*objects = new;
	*n_obj += 1;
	return (*objects);
}

static t_obj	*assign_2(char *line, t_obj **objects, size_t *n_obj)
{
	if (ft_strnstr(line, "p ", 2))
		(*objects)[*n_obj].pos = parse_vec(line + 2);
	if (ft_strnstr(line, "c ", 2))
		(*objects)[*n_obj].mat.rgb = parse_color(line + 2);
	return (*objects);
}

static t_obj	*assign(char *line, t_obj **objects, size_t *n_obj)
{
	line = ft_strtrim(line);
	if (*line == '#')
		return (*objects);
	if (ft_strnstr(line, "sphere ", 7))
		return (create_obj(SPHERE, line + 7, objects, n_obj));
	if (ft_strnstr(line, "cone ", 5))
		return (create_obj(CONE, line + 5, objects, n_obj));
	if (ft_strnstr(line, "cylinder ", 8))
		return (create_obj(CYLINDER, line + 8, objects, n_obj));
	if (ft_strnstr(line, "plane ", 6))
		return (create_obj(PLANE, line + 6, objects, n_obj));
	if (ft_strnstr(line, "o ", 2))
		return (create_obj(MESH, line + 2, objects, n_obj));
	return (assign_2(line, objects, n_obj));
}

t_obj			*parse(int fd)
{
	char		*line;
	t_obj		*objects;
	size_t		n_obj;

	line = NULL;
	objects = NULL;
	n_obj = 0;
	while (get_next_line(fd, &line) > 0)
	{
		objects = assign(line, &objects, &n_obj);
		printf("line result :\n");
		if (n_obj > 1)
		{
			printf("	Object color : %d %d %d\n",
					objects[1].mat.rgb.r,
					objects[1].mat.rgb.g,
					objects[1].mat.rgb.b);
			printf("	Object position : %f %f %f\n",
					objects[1].pos.x,
					objects[1].pos.y,
					objects[1].pos.z);
		}
		free(line);
	}
	objects = create_obj(BACKSLASH, "n/a", &objects, &n_obj);
	return (objects);
}
