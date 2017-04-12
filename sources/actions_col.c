/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_col.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:33:41 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/12 15:31:14 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_compnt		action_col(struct s_compnt compnt, t_env *env)
{
	int x;
	int y;

	x = env->ui->mouse_x - compnt.x;
	y = env->ui->mouse_y - compnt.y;
	env->ui->color = ((t_color *)compnt.img.addr)[y * compnt.img.width + x];
	return (compnt);
}

t_compnt		hover_col(struct s_compnt compnt, t_env *env)
{
	compnt.status = HOVER;
	return (compnt);
}

t_compnt		idle_col(struct s_compnt compnt, t_env *env)
{
	compnt.status = IDLE;
	return (compnt);
}
