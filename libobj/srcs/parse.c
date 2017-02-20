/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:30:05 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/20 11:44:22 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <obj.h>

static t_obj *create_obj(t_type type, char *name, t_obj *objs, size_t *n_obj)
{
	objs[*n_obj].type = type;
	objs[*n_obj].name = ft_strdup(name);
	objs[*n_obj].mat.rgb = (t_color) {255, 255, 255, 0};
	objs[*n_obj].mat.coef = new_vector(1, 1, 1);
	objs[*n_obj].mat.reflect = 0.0;
	objs[*n_obj].mat.refract = 0.0;
	objs[*n_obj].rot = NULL;
	*n_obj += 1;
	return (objs);
}

static t_obj	*assign2(char *line, t_obj *objs, size_t *n_obj)
{
	if (ft_strnstr(line, "p ", 2))
		objs[*n_obj - 1].pos = parse_vec(line + 2);
	if (ft_strnstr(line, "c ", 2))
		objs[*n_obj - 1].mat.rgb = parse_color(line + 2);
	if (ft_strnstr(line, "n ", 2))
		objs[*n_obj - 1].dir = parse_vec(line + 2);
	if (ft_strnstr(line, "radius ", 7))
		objs[*n_obj - 1].radius = parse_double(line + 7);
	if (ft_strnstr(line, "r ", 2))
		objs[*n_obj - 1].radius = parse_double(line + 2);
	return (objs);
}

static t_obj	*assign(char *line, t_obj *objs, size_t *n_obj)
{
	if (*line == '#')
		return (objs);
	if (ft_strnstr(line, "sphere ", 7))
		return (create_obj(SPHERE, line + 7, objs, n_obj));
	if (ft_strnstr(line, "cone ", 5))
		return (create_obj(CONE, line + 5, objs, n_obj));
	if (ft_strnstr(line, "cylinder ", 8))
		return (create_obj(CYLINDER, line + 8, objs, n_obj));
	if (ft_strnstr(line, "plane ", 6))
		return (create_obj(PLANE, line + 6, objs, n_obj));
	//if (ft_strnstr(line, "o ", 2))
	//	return (create_obj(MESH, line + 2, objs, n_obj));
	return (assign2(line, objs, n_obj));
}

t_obj			*parse(int fd)
{
	char		*line;
	t_obj		*objs;
	size_t		n_obj;

	line = NULL;
	objs = (t_obj *)malloc(sizeof(t_obj) * 200);
	n_obj = 0;
	while (get_next_line(fd, &line) > 0)
	{
		line = ft_strtrim(line);
		objs = assign(line, objs, &n_obj);
		free(line);
	}
	objs = create_obj(BACKSLASH, "n/a", objs, &n_obj);
	return (objs);
}
