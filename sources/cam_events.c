/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:15:42 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/07 14:55:38 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_cam			change_mod(t_cam cam)
{
	if (cam.control == MOVEMENT)
		cam.control = ROTATION;
	else
		cam.control = MOVEMENT;
	return (cam);
}

static t_cam	cam_execute(t_cam cam, t_dir dir, t_env *env)
{
	if (cam.control == MOVEMENT)
		cam = move_camera(cam, dir);
	else
		cam = camera_control(cam, dir);
	env->redraw = 1;
	return (cam);
}

t_cam			cam_handle(t_cam cam, t_env *env)
{
	if (env->ui->keystatus[A_UP] == 1 && env->ui->keystatus[A_DOWN] != 1)
		cam = cam_execute(cam, UP, env);
	else if (env->ui->keystatus[A_DOWN] == 1 && env->ui->keystatus[A_UP] != 1)
		cam = cam_execute(cam, DOWN, env);
	if (env->ui->keystatus[A_LEFT] == 1 && env->ui->keystatus[A_RIGHT] != 1)
		cam = cam_execute(cam, LEFT, env);
	else if (env->ui->keystatus[A_RIGHT] == 1 && env->ui->keystatus[A_LEFT] != 1)
		cam = cam_execute(cam, RIGHT, env);
	if (env->ui->keystatus[N_ADD] == 1 && env->ui->keystatus[N_SUB] != 1)
		cam = cam_execute(cam, FRONT, env);
	else if (env->ui->keystatus[N_SUB] == 1 && env->ui->keystatus[N_ADD] != 1)
		cam = cam_execute(cam, BACK, env);
	return (cam);
}
