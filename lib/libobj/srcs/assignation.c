/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <hsabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 19:17:55 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/18 14:06:38 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj.h"

static t_env	step2_objs(char *line, t_env env)
{
	if (ft_strnstr(line, "p ", 2))
		env.objs[env.n_obj - 1].pos = parse_vec(line + 2);
	if (ft_strnstr(line, "c ", 2))
		env.objs[env.n_obj - 1].mat.rgb = parse_color(line + 2);
	if (ft_strnstr(line, "n ", 2))
		env.objs[env.n_obj - 1].dir = parse_vec(line + 2);
	if (ft_strnstr(line, "radius ", 7))
		env.objs[env.n_obj - 1].radius = parse_double(line + 7);
	if (ft_strnstr(line, "refract ", 8))
		env.objs[env.n_obj - 1].mat.refract = parse_double(line + 8);
	if (ft_strnstr(line, "alpha ", 6))
		env.objs[env.n_obj - 1].mat.alpha = parse_double(line + 6);
	if (ft_strnstr(line, "reflect ", 8))
		env.objs[env.n_obj - 1].mat.reflect = ft_atof(line + 8);
	if (ft_strnstr(line, "texture ", 8))
		env.objs[env.n_obj - 1].mat.texture = parse_asset(line + 8, env);
	if (ft_strnstr(line, "type ", 5))
		env.objs[env.n_obj - 1].mat.texture.type = type_of_objs(line + 5);
	if (ft_strnstr(line, "r ", 2))
		env.objs[env.n_obj - 1].rot = parse_quat(line + 2,\
		&env.objs[env.n_obj - 1].inv);
	if (ft_strnstr(line, "child", 6))
		temp_init(&env, env.n_obj - 1);
	return (env);
}

static t_env	step2_lgts(char *line, t_env env)
{
	if (ft_strnstr(line, "p ", 2))
		env.lgt[env.n_lgt - 1].pos = parse_vec(line + 2);
	if (ft_strnstr(line, "c ", 2))
		env.lgt[env.n_lgt - 1].rgb = parse_color(line + 2);
	if (ft_strnstr(line, "n ", 2))
		env.lgt[env.n_lgt - 1].dir = parse_vec(line + 2);
	return (env);
}

t_env			objs(char *line, t_env env)
{
	if (*line == '#')
		return (env);
	if (ft_strnstr(line, "sphere ", 7))
		return (create_obj(SPHERE, line + 7, env));
	if (ft_strnstr(line, "cone ", 5))
		return (create_obj(CONE, line + 5, env));
	if (ft_strnstr(line, "cylinder ", 9))
		return (create_obj(CYLINDER, line + 9, env));
	if (ft_strnstr(line, "plane ", 6))
		return (create_obj(PLANE, line + 6, env));
	if (ft_strnstr(line, "o ", 2))
		return (create_obj(MESH, line + 2, env));
	if (static_keeper(0, 0) == 1)
		return (step2_objs(line, env));
	return (env);
}

t_env			lgts(char *line, t_env env)
{
	if (*line == '#')
		return (env);
	if (ft_strnstr(line, "omni ", 5))
		return (create_lgt(OMNI, line + 5, env));
	if (ft_strnstr(line, "spot ", 5))
		return (create_lgt(SPOT, line + 5, env));
	if (static_keeper(0, 0) == 2)
		return (step2_lgts(line, env));
	return (env);
}

t_env			meshs(char *line, t_env env)
{
	if (*line == '#')
		return (env);
	if (ft_strnstr(line, "o ", 2))
		return (create_obj(MESH, line + 2, env));
	if (ft_strnstr(line, "v ", 2))
		return (create_vrt(line + 2, env));
	if (ft_strnstr(line, "f ", 2))
		return (add_poly_to_last(line + 2, env));
	return (env);
}
