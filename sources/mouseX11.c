/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouseX11.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:15:42 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/10 18:09:16 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static int	mouse_hook(int x, int y, t_env *env)
{
	if (((t_color *)(env->ui->lay1.addr))\
	[y * env->ui->lay1.width + x].a == 255 && env->ui->place.type != BACKSLASH)
	{
		place_obj(x, y, env, env->ui->place);
		display_objs(env->objs, env->n_obj);
		env->ui->place.type = BACKSLASH;
	}
	return (0);
}

int			mouse(int x, int y, t_env *env)
{
	env->ui->mouse_x = x;
	env->ui->mouse_y = y;
	return (0);
}

int			button_press(int button, int x, int y, t_env *env)
{
	env->ui->mouse_x = x;
	env->ui->mouse_y = y;
	env->ui->click = 1;
	if (button == 1)
		return (mouse_hook(x, y, env));
	else
		return (0);
}

int			button_release(int button, int x, int y, t_env *env)
{
	env->ui->mouse_x = x;
	env->ui->mouse_y = y;
	env->ui->click = 0;
	return (0);
}


