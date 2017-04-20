/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouseX11.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:15:42 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/20 16:16:25 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static int	mouse_hook(int x, int y, t_env *env)
{
	if (!(x > 0 && x < env->img.width && y > 0 && y < env->img.height))
		return (0);
	if (((t_color *)(env->ui->lay1.addr))\
	[y * env->ui->lay1.width + x].a == 255 &&\
	(env->ui->place.type != BACKSLASH || env->ui->delete == 1))
	{
		place_obj(x, y, env, env->ui->place);
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
	if (button != 0)
	{
		env->ui->mouse_x = x;
		env->ui->mouse_y = y;
		env->ui->click = 0;
	}
	return (0);
}
