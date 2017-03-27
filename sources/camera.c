/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:52:33 by ple-lez           #+#    #+#             */
/*   Updated: 2017/03/03 15:36:58 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_cam		init_cam(t_vec4 pos, t_quat rot, double fov)
{
	t_cam	cam;

	cam.pos = new_vector(pos.x, pos.y, pos.z);
	cam.rot = rot;
	cam.fov = fov;
	cam.control = MOVEMENT;
	return (cam);
}

t_cam		translate_cam(t_cam cam, t_vec4 tran)
{
	cam.pos = vector_add(cam.pos, tran);
	return (cam);
}

t_cam		rotate_cam(t_cam cam, t_quat rot)
{
	cam.rot = quat_mult(rot, cam.rot);
	return (cam);
}

t_cam		camera_control(t_cam cam, t_dir dir)
{
	t_quat	rot;
	t_vec4	axis;

	if (dir == FRONT)
		axis = new_vector(0, 0, 1);
	else if (dir == BACK)
		axis = new_vector(0, 0, -1);
	else if (dir == RIGHT)
		axis = new_vector(0, -1, 0);
	else if (dir == LEFT)
		axis = new_vector(0, 1, 0);
	else if (dir == DOWN)
		axis = new_vector(-1, 0, 0);
	else
		axis = new_vector(1, 0, 0);
	rot = new_quat(PI / 180, axis);
	cam = rotate_cam(cam, rot);
	return (cam);
}

t_cam		move_camera(t_cam cam, t_dir dir)
{
	t_vec4	tran;

	if (dir == FRONT)
		tran = new_vector(0, 0, 0.1);
	else if (dir == BACK)
		tran = new_vector(0, 0, -0.1);
	else if (dir == RIGHT)
		tran = new_vector(0.1, 0, 0);
	else if (dir == LEFT)
		tran = new_vector(-0.1, 0, 0);
	else if (dir == DOWN)
		tran = new_vector(0, -0.1, 0);
	else
		tran = new_vector(0, 0.1, 0);
	cam = translate_cam(cam, tran);
	return (cam);
}
