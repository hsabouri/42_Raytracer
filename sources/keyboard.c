/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 20:20:20 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/12 15:15:14 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static t_env*	key_hook(int keycode, t_env *env)
{
	if (keycode == KEY_R && (env->redraw = 1))
		env->cam = change_mod(env->cam);
	if (keycode == KEY_S && (env->redraw = 1))
		env->shadow = 1 - env->shadow;
	if (keycode == KEY_P)
		env->pr_mesh = env->pr_mesh ? 0 : 1;
	return (0);
}

t_env			*key_actions(t_env *env)
{
	env->cam = cam_handle(env->cam, env);
	return (env);
}


int				keypress(int keycode, t_env *env)
{
	if (keycode < 127 && keycode >= 0)
	{
		if (env->ui->keystatus[keycode] == 0)
			key_hook(keycode, env);
		env->ui->keystatus[keycode] = 1;
	}
	if (keycode == KEY_ESC)
		exit_clean(env);
	return (0);
}

int				keyrelease(int keycode, t_env *env)
{
	if (keycode < 127 && keycode >= 0)
		(env->ui->keystatus)[keycode] = 0;
	return (0);
}