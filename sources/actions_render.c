/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 02:31:15 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/10 17:41:24 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_compnt		action_c(struct s_compnt compnt, t_env *env)
{
	compnt.status = ACTION;
	((t_compnt *)(compnt.value))->bg = (t_color) {30, 30, 30, 0};
	compnt.bg = (t_color){70, 70, 70, 0};
	if (compnt.id == 2 && env->render == 1)
	{
		env->render = 0;
		env->shadow = 0;
		env->redraw = 1;
	}
	if (compnt.id == 3 && env->render == 0)
	{
		env->render = 1;
		env->shadow = 1;
		env->redraw = 1;
	}
	return (compnt);
}

t_compnt		hover_c(struct s_compnt compnt, t_env *env)
{
	compnt.status = HOVER;
	compnt = compnt.idle(compnt, env);
	return (compnt);
}

t_compnt		idle_c(struct s_compnt compnt, t_env *env)
{
	compnt.status = IDLE;
	if (compnt.id == 2 && env->render == 0)
		compnt = compnt.action(compnt, env);
	if (compnt.id == 3 && env->render == 1)
		compnt = compnt.action(compnt, env);
	return (compnt);
}
