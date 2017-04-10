/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:33:41 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/10 16:22:59 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_compnt		action_a(struct s_compnt compnt, t_env *env)
{
	compnt.status = ACTION;
	env->ui->place = *((t_obj *)compnt.value);
	return (compnt);
}

t_compnt		hover_a(struct s_compnt compnt, t_env *env)
{
	compnt.status = HOVER;
	return (compnt);
}

t_compnt		idle_a(struct s_compnt compnt, t_env *env)
{
	compnt.status = IDLE;
	return (compnt);
}
