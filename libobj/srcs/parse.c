/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:30:05 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/21 09:55:19 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <obj.h>

int			static_keeper(int new, int to_change)
{
	static int kept = 0;

	if (to_change > 0)
		kept = new;
	return (kept);
}

t_obj		*create_obj(t_type type, char *name, t_obj *objs, size_t *n_obj)
{
	static_keeper(1, 1);
	objs[*n_obj].type = type;
	objs[*n_obj].name = ft_strdup(name);
	objs[*n_obj].mat.rgb = (t_color) {255, 255, 255, 0};
	objs[*n_obj].mat.coef = new_vector(1, 1, 1);
	objs[*n_obj].pos = new_vector(0, 0, 0);
	objs[*n_obj].mat.reflect = 0.0;
	objs[*n_obj].mat.refract = 0.0;
	objs[*n_obj].rot = NULL;
	*n_obj += 1;
	return (objs);
}

t_lgt		*create_lgt(t_ltype type, char *name, t_lgt *lgts, size_t *n_lgt)
{
	static_keeper(2, 1);
	lgts[*n_lgt].type = type;
	lgts[*n_lgt].name = ft_strdup(name);
	lgts[*n_lgt].rgb = (t_color) {255, 255, 255, 0};
	lgts[*n_lgt].pos = new_vector(0, 0, 0);
	lgts[*n_lgt].dir = new_vector(0, 0, 0);
	*n_lgt += 1;
	return (lgts);
}

t_env		parse(int fd, t_env env)
{
	char		*line;
	size_t		n_obj;
	size_t		n_lgt;

	line = NULL;
	env.objs = (t_obj *)malloc(sizeof(t_obj) * 200);
	env.lgt = (t_lgt *)malloc(sizeof(t_lgt) * 200);
	n_obj = 0;
	n_lgt = 0;
	while (get_next_line(fd, &line) > 0)
	{
		line = ft_strtrim(line);
		env.objs = assign_objs(line, env.objs, &n_obj);
		env.lgt = assign_lgts(line, env.lgt, &n_lgt);
		free(line);
	}
	env.objs = create_obj(BACKSLASH, "n/a", env.objs, &n_obj);
	env.lgt = create_lgt(NOLIGHT, "n/a", env.lgt, &n_lgt);
	env.n_lgt = (unsigned int)n_lgt;
	return (env);
}
