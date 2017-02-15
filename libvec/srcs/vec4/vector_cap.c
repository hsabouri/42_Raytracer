/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_cap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:57:09 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/15 14:05:36 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

t_vec4		vector_cap(t_vec4 vec, double min, double max)
{
	t_vec4	res;

	res.x = (vec.x < min) ? min : vec.x;
	res.y = (vec.y < min) ? min : vec.y;
	res.z = (vec.z < min) ? min : vec.z;
	res.x = (vec.x > max) ? max : vec.x;
	res.y = (vec.y > max) ? max : vec.y;
	res.z = (vec.z > max) ? max : vec.z;
	return (res);
}
