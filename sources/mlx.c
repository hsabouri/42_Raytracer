/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:15:42 by hsabouri          #+#    #+#             */
/*   Updated: 2017/03/19 13:05:24 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static t_cam	change_mod(t_cam cam)
{
	if (cam.control == MOVEMENT)
		cam.control = ROTATION;
	else
		cam.control = MOVEMENT;
	return (cam);
}

static t_cam	cam_handle(int keycode, t_cam cam)
{
	t_dir	dir;

	if (keycode == A_UP)
		dir = UP;
	else if (keycode == A_DOWN)
		dir = DOWN;
	else if (keycode == A_LEFT)
		dir = LEFT;
	else if (keycode == A_RIGHT)
		dir = RIGHT;
	else if (keycode == N_ADD)
		dir = FRONT;
	else if (keycode == N_SUB)
		dir = BACK;
	if (cam.control == MOVEMENT)
		cam = move_camera(cam, dir);
	else
		cam = camera_control(cam, dir);
	return (cam);
}

int				key_hook(int keycode, t_env *env)
{
	env->redraw = 1;
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_R)
		env->cam = change_mod(env->cam);
	else if (keycode == KEY_S)
		env->shadow = 1 - env->shadow;
	else if (keycode == KEY_P)
		env->pr_mesh = env->pr_mesh ? 0 : 1;
	else if (keycode == A_UP || keycode == A_DOWN ||
			keycode == A_LEFT || keycode == A_RIGHT ||
			keycode == N_ADD || keycode == N_SUB)
	{
		//env->pr_mesh = env->pr_mesh ? 0 : 1;
		env->cam = cam_handle(keycode, env->cam);
	}
	return (0);
}

t_img			pixel_put(t_img img, unsigned int x, unsigned int y, t_color color)
{
	if (x < LENGTH && y < HEIGHT)
		((t_color *)(img.addr))[x + y * LENGTH] = color;
	return (img);
}
