/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:15:42 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/03 15:28:05 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void	change_mod(t_cam *cam)
{
	if (cam->control == MOVEMENT)
		cam->control = ROTATION;
	else
		cam->control = MOVEMENT;
}

static void	cam_handle(int keycode, t_cam *cam)
{
	t_dir	dir;

	if (keycode == KEY_AUP)
		dir = UP;
	else if (keycode == KEY_ADN)
		dir = DOWN;
	else if (keycode == KEY_ALF)
		dir = LEFT;
	else if (keycode == KEY_ART)
		dir = RIGHT;
	else if (keycode == KEY_PL)
		dir = FRONT;
	else if (keycode == KEY_MN)
		dir = BACK;
	if (cam->control == MOVEMENT)
		move_camera(cam, dir);
	else
		camera_control(cam, dir);
}

int			key_hook(int keycode, t_env *env)
{
	env->redraw = 1;
	if (keycode == KEY_ES)
		exit(0);
	else if (keycode == KEY_R)
		change_mod(env->cam);
	else if (keycode == KEY_AUP || keycode == KEY_ADN ||
			keycode == KEY_ALF || keycode == KEY_ART ||
			keycode == KEY_PL || keycode == KEY_MN)
		cam_handle(keycode, env->cam);
	return (0);
}

void		pixel_put(t_env env, unsigned int x, unsigned int y, t_color color)
{
	if (x < LENGTH && y < HEIGHT)
		((t_color *)(env.addr))[x + y * LENGTH] = color;
}
