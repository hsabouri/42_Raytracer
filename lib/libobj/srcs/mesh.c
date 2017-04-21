/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <hsabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:11:00 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/21 15:50:58 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <obj.h>

static t_uint3		parse_polygon(char *line, t_env env)
{
	t_uint3			res;
	unsigned int	*ids;

	ids = (unsigned int *)(&res);
	while (!ft_isdigit(*line))
		line++;
	ids[0] = ft_atoi(line);
	while (!ft_isspace(*line))
		line++;
	while (!ft_isdigit(*line))
		line++;
	ids[1] = ft_atoi(line);
	while (!ft_isspace(*line))
		line++;
	while (!ft_isdigit(*line))
		line++;
	ids[2] = ft_atoi(line);
	if (!(ids[0] <= env.n_vrt && ids[0] >= 1 &&\
	ids[1] <= env.n_vrt && ids[1] >= 1 &&\
	ids[2] <= env.n_vrt && ids[2] >= 1))
		error(PARSING_ERROR, "Vertice does not exist");
	return (res);
}

t_env				add_poly_to_last(char *line, t_env env)
{
	static unsigned int n_poly = 0;
	t_obj				poly;
	t_uint3				s_ids;
	unsigned int		*ids;
	char				*tmp;

	s_ids = parse_polygon(line, env);
	ids = (unsigned int *)(&s_ids);
	poly.type = POLYGON;
	poly.lst = 0;
	poly.mat.reflect = -1.0;
	poly.mat.alpha = -1.0;
	poly.mat.texture.type = NOTEX;
	tmp = ft_itoa(n_poly);
	poly.name = ft_strjoin("poly ", tmp);
	free(tmp);
	poly.vert[0] = env.vrts[ids[0] - 1];
	poly.vert[1] = env.vrts[ids[1] - 1];
	poly.vert[2] = env.vrts[ids[2] - 1];
	env.objs[env.n_obj - 1] = add_polygon(env.objs[env.n_obj - 1], poly);
	n_poly += 1;
	return (env);
}

t_env				create_vrt(char *line, t_env env)
{
	env.vrts[env.n_vrt] = parse_vec(line);
	env.n_vrt += 1;
	return (env);
}
