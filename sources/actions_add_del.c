/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_add_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:33:41 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/20 16:18:09 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_compnt		action_del(struct s_compnt compnt, t_env *env)
{
	compnt.status = ACTION;
	if (env->ui->delete == 1)
		env->ui->delete = 0;
	else
		env->ui->delete = 1;
	return (compnt);
}

t_compnt		action_a(struct s_compnt compnt, t_env *env)
{
	compnt.status = ACTION;
	if (env->ui->place.type == BACKSLASH ||\
	(*((t_obj *)compnt.value)).type != env->ui->place.type)
		env->ui->place = *((t_obj *)compnt.value);
	else
		env->ui->place.type = BACKSLASH;
	env->ui->delete = 0;
	return (compnt);
}

t_compnt		hover_def(struct s_compnt compnt, t_env *env)
{
	if (env != NULL)
		compnt.status = HOVER;
	return (compnt);
}

t_compnt		idle_a(struct s_compnt compnt, t_env *env)
{
	if (((t_obj *)compnt.value)->type == env->ui->place.type)
		compnt.status = HOVER;
	else
		compnt.status = IDLE;
	return (compnt);
}

t_compnt		idle_del(struct s_compnt compnt, t_env *env)
{
	if (env->ui->delete == 1)
		compnt.status = HOVER;
	else
		compnt.status = IDLE;
	return (compnt);
}
