/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 02:31:15 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/07 16:54:54 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_compnt		action_r(struct s_compnt compnt, t_env *env)
{
	compnt.status = ACTION;
	((t_compnt *)(compnt.value))->bg = (t_color) {30, 30, 30, 0};
	compnt.bg = (t_color){70, 70, 70, 0};
	if (compnt.id == 0)
		env->cam.control = ROTATION;
	else
		env->cam.control = MOVEMENT;
	return (compnt);
}

t_compnt		hover_r(struct s_compnt compnt, t_env *env)
{
	compnt.status = HOVER;
	compnt = compnt.idle(compnt, env);
	return (compnt);
}

t_compnt		idle_r(struct s_compnt compnt, t_env *env)
{
	compnt.status = IDLE;
	if (compnt.id == 0 && env->cam.control == ROTATION)
		compnt = compnt.action(compnt, env);
	if (compnt.id == 1 && env->cam.control == MOVEMENT)
		compnt = compnt.action(compnt, env);
	return (compnt);
}
