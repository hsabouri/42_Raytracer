/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouseX11.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:15:42 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/07 17:01:47 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int	mouse(int x, int y, t_env *env)
{
	env->ui->mouse_x = x;
	env->ui->mouse_y = y;
	return (0);
}

int button_press(int button, int x, int y, t_env *env)
{
	env->ui->mouse_x = x;
	env->ui->mouse_y = y;
	env->ui->click = 1;
	return (0);
}

int button_release(int button, int x, int y, t_env *env)
{
	env->ui->mouse_x = x;
	env->ui->mouse_y = y;
	env->ui->click = 0;
	return (0);
}
