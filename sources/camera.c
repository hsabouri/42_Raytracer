/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:52:33 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/04 19:43:08 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_cam		*init_cam(t_vec pos, t_quat *rot, double fov)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	cam->pos = (t_vec *)malloc(sizeof(t_vec));
	*cam->pos = new_vector(pos.x, pos.y, pos.z);
	cam->rot = rot;
	cam->fov = fov;
	cam->control = MOVEMENT;
	return (cam);
}

void		translate_cam(t_cam *cam, t_vec tran)
{
	*(cam->pos) = vector_add(*cam->pos, tran);
}

void		rotate_cam(t_cam *cam, t_quat *rot)
{
	if (cam->rot)
		*(cam->rot) = quat_mult(cam->rot, rot);
	else
		cam->rot = rot;
}

void		camera_control(t_cam *cam, t_dir dir)
{
	t_quat	rot;
	t_vec	axis;

	if (dir == FRONT)
		axis = new_vector(0, 0, 1);
	else if (dir == BACK)
		axis = new_vector(0, 0, 1);
	else if (dir == RIGHT)
		axis = new_vector(1, 0, 0);
	else if (dir == LEFT)
		axis = new_vector(1, 0, 0);
	else if (dir == DOWN)
		axis = new_vector(0, 1, 0);
	else
		axis = new_vector(0, 1, 0);
	rot = new_quat(PI / 10, axis);
	rotate_cam(cam, &rot);
}

void		move_camera(t_cam *cam, t_dir dir)
{
	t_vec	tran;
	
	if (dir == FRONT)
		tran = new_vector(0, 0, 1);
	else if (dir == BACK)
		tran = new_vector(0, 0, -1);
	else if (dir == RIGHT)
		tran = new_vector(1, 0, 0);
	else if (dir == LEFT)
		tran = new_vector(-1, 0, 0);
	else if (dir == DOWN)
		tran = new_vector(0, -1, 0);
	else
		tran = new_vector(0, 1, 0);
	translate_cam(cam, tran);
}
