/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_assignation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:33:53 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/06 14:25:54 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj.h"

static t_env	set_camera(t_env env)
{
	static_keeper(3, 1);
	return (env);
}

static t_env	step2_env_feed(char *line, t_env env)
{
	if (ft_strnstr(line, "p ", 2))
		env.cam.pos = parse_vec(line + 2);
	if (ft_strnstr(line, "r ", 2))
		env.cam.rot = parse_quat(line + 2, NULL);
	if (ft_strnstr(line, "fov ", 4))
		env.cam.fov = parse_double(line + 4);
	return (env);
}

t_env			env_feed(char *line, t_env env)
{
	if (ft_strnstr(line, "camera", 6))
		return (set_camera(env));
	if (ft_strnstr(line, "width ", 6))
		env.width = ft_atoi(line + 6);
	if (ft_strnstr(line, "height ", 7))
		env.height = ft_atoi(line + 7);
	if (static_keeper(0, 0) == 3)
		return (step2_env_feed(line, env));
	return (env);
}
