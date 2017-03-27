/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 02:31:15 by hsabouri          #+#    #+#             */
/*   Updated: 2017/03/16 17:34:40 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_compnt		action_test(struct s_compnt compnt, t_env env)
{
	env.ui->redraw = 1;
	compnt.status = ACTION;
	return (compnt);
}

t_compnt		hover_test(struct s_compnt compnt, t_env env)
{
	env.ui->redraw = 1;
	compnt.status = HOVER;
	return (compnt);
}

t_compnt		idle_test(struct s_compnt compnt, t_env env)
{
	//t_vec4 first;
	//t_quat rot;

	compnt.status = IDLE;
	//first = (t_vec4) {1, 0, 0, 1};
	//rot = env.cam.rot;
	//first = quat_rot(rot, first);
	//print_vector(first);
	return (compnt);
}