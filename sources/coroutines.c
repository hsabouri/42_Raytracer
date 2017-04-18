/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coroutines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:50:00 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/17 22:47:14 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	cancel_coroutine(t_env *env)
{
	if (env->drawing && env->frame % 10 == 0)
	{
		pthread_cancel(env->render_thread);
		env->drawing = 0;
	}
}

void	render_coroutine(t_env *env)
{
	if (env->drawing == 1)
		pthread_cancel(env->render_thread);
	pthread_create(&env->render_thread, NULL, draw, env);
}
