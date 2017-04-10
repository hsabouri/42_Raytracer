/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <hsabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 20:20:20 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/10 16:33:08 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static t_env*	key_hook(int keycode, t_env *env)
{
	t_ui *test;

	test = (t_ui *)ft_malloc(sizeof(t_ui), CLEAN);
	if (keycode == KEY_R && (env->redraw = 1))
		env->cam = change_mod(env->cam);
	if (keycode == KEY_S && (env->redraw = 1))
		env->shadow = 1 - env->shadow;
	if (keycode == KEY_P)
		env->pr_mesh = env->pr_mesh ? 0 : 1;
	if (keycode == KEY_SPACE)
	{
		env->cam = init_cam(new_vector(0, 0, -4), new_quat_null(), 66);
		env->redraw = 1;
	}
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
