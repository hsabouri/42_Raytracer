/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <hsabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:30:05 by hsabouri          #+#    #+#             */
/*   Updated: 2017/03/08 19:25:27 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <obj.h>

static void	free_lines(char *line, char *line2)
{
	free(line);
	free(line2);
}

int			static_keeper(int new, int to_change)
{
	static int kept = 0;

	if (to_change > 0)
		kept = new;
	return (kept);
}

t_env		create_obj(t_type type, char *name, t_env env)
{
	static_keeper(1, 1);
	if (type == MESH && env.n_obj < 200)
	{
		env.objs[env.n_obj] = create_mesh((t_color) {255, 255, 255, 0}, name);
		env.n_vrt = 0;
	}
	else if (env.n_obj < 200)
	{
		env.objs[env.n_obj].type = type;
		env.objs[env.n_obj].name = ft_strdup(name);
		env.objs[env.n_obj].mat.rgb = (t_color) {255, 255, 255, 0};
		env.objs[env.n_obj].mat.coef = new_vector(1, 1, 1);
		env.objs[env.n_obj].pos = new_vector(0, 0, 0);
		env.objs[env.n_obj].mat.reflect = 0;
		env.objs[env.n_obj].mat.refract = EPSILON;
		env.objs[env.n_obj].rot = NULL;
		env.objs[env.n_obj].inv = NULL;
	}
	env.n_obj += 1;
	return (env);
}

t_env		create_lgt(t_ltype type, char *name, t_env env)
{
	static_keeper(2, 1);
	env.lgt[env.n_lgt].type = type;
	env.lgt[env.n_lgt].name = ft_strdup(name);
	env.lgt[env.n_lgt].rgb = (t_color) {255, 255, 255, 0};
	env.lgt[env.n_lgt].pos = new_vector(0, 0, 0);
	env.lgt[env.n_lgt].dir = new_vector(0, 0, 0);
	env.n_lgt += 1;
	return (env);
}

t_env		parse(int fd, t_env env)
{
	char		*line;
	char		*line2;
	t_vec4		*ver;

	line = NULL;
	ver = NULL;
	env.objs = (t_obj *)malloc(sizeof(t_obj) * 200);
	env.lgt = (t_lgt *)malloc(sizeof(t_lgt) * 200);
	env.vrts = (t_vec4 *)malloc(sizeof(t_vec4) * 600);
	env.n_lgt = 0;
	env.n_obj = 0;
	env.n_vrt = 0;
	while (get_next_line(fd, &line) > 0)
	{
		line2 = ft_strtrim(line);
		env = objs(line2, env);
		env = lgts(line2, env);
		env = meshs(line2, env);
		free_lines(line, line2);
	}
	free(line);
	env = create_obj(BACKSLASH, "n/a", env);
	env = create_lgt(NOLIGHT, "n/a", env);
	ft_putendl("\x1B[32mLOG\x1B[0m: Parsing done");
	return (env);
}
