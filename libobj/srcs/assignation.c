/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 19:17:55 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/21 09:59:01 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <obj.h>

static t_lgt	*step2_lgts(char *line, t_lgt *lgts, size_t *n_lgt)
{
	if (ft_strnstr(line, "p ", 2))
		lgts[*n_lgt - 1].pos = parse_vec(line + 2);
	if (ft_strnstr(line, "c ", 2))
		lgts[*n_lgt - 1].rgb = parse_color(line + 2);
	if (ft_strnstr(line, "n ", 2))
		lgts[*n_lgt - 1].dir = parse_vec(line + 2);
	return (lgts);
}

static t_obj	*step2_objs(char *line, t_obj *objs, size_t *n_obj)
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
		objs[*n_obj - 1].rot = parse_quat(line + 2,  objs + *n_obj - 1);
	return (objs);
}

t_obj			*assign_objs(char *line, t_obj *objs, size_t *n_obj)
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
	if (static_keeper(0, 0) == 1)
		return (step2_objs(line, objs, n_obj));
	return (objs);
}

t_lgt			*assign_lgts(char *line, t_lgt *lgts, size_t *n_lgt)
{
	if (*line == '#')
		return (lgts);
	if (ft_strnstr(line, "omni ", 5))
		return (create_lgt(OMNI, line + 5, lgts, n_lgt));
	if (ft_strnstr(line, "spot ", 5))
		return (create_lgt(SPOT, line + 5, lgts, n_lgt));
	if (static_keeper(0, 0) == 2)
		return (step2_lgts(line, lgts, n_lgt));
	return (lgts);
}
