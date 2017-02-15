/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:37:39 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/15 15:43:20 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_ray		rotate_ray(t_ray ray, t_quat *rot)
{
	t_ray	res;

	res.dir = quat_rot(rot, &res.dir);
	res.org = quat_rot(rot, &res.org);
	return (ray);
}
