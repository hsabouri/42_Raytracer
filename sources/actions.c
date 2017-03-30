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

t_compnt		action_test(struct s_compnt compnt, t_env *env)
{
	static int status = 0;

	compnt.status = ACTION;
	if (status == 0)
	{

		status = 1;
	}
	return (compnt);
}

t_compnt		hover_test(struct s_compnt compnt, t_env *env)
{
	compnt.status = HOVER;
	return (compnt);
}

t_compnt		idle_test(struct s_compnt compnt, t_env *env)
{
	compnt.status = IDLE;
	return (compnt);
}