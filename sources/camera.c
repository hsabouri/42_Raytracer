/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:52:33 by ple-lez           #+#    #+#             */
/*   Updated: 2017/01/29 22:11:31 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_cam		*init_cam(t_vec *pos, t_quat *rot, double fov)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	cam->pos = pos;
	cam->rot = rot;
	cam->fov = fov;
	return (cam);
}

void		rotate_cam(t_cam *cam, t_quat *rot)
{
	*(cam->rot) = quat_mult(cam->rot, rot);
}
