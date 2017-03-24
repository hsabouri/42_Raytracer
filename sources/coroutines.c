/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coroutines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:50:00 by hsabouri          #+#    #+#             */
/*   Updated: 2017/03/20 11:37:16 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			render_coroutine(t_env *env)
{
	if (env->drawing == 1)
		pthread_cancel(env->render_thread);
	pthread_create(&env->render_thread, NULL, draw, env);
}