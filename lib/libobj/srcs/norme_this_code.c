/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_this_code.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:52:13 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/20 21:37:52 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <obj.h>

t_env	parse_pipeline(t_env env, char *line2)
{
	env = objs(line2, env);
	env = lgts(line2, env);
	env = meshs(line2, env);
	env = env_feed(line2, env);
	return (env);
}

t_obj	obj_default(t_type type, char *name)
{
	t_obj ret;

	ret.chld = NULL;
	ret.ch_type = NOCHILD;
	ret.type = type;
	ret.lst = 0;
	ret.name = ft_strdup(name);
	ret.mat.rgb = (t_color) {255, 255, 255, 0};
	ret.mat.coef = new_vector(1, 1, 1);
	ret.pos = new_vector(0, 0, 0);
	ret.mat.reflect = -1.0;
	ret.dir = new_vector(0, 1, 0);
	ret.rot = new_quat_null();
	ret.inv = get_inverse(ret.rot);
	ret.mat.texture.img = NULL;
	ret.mat.texture.type = NOTEX;
	return (ret);
}
