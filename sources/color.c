/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 14:45:46 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/08 14:50:13 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vec		vector_cap(t_vec vec, double min, double max)
{
	t_vec	res;

	res.x = (vec.x < min) ? min : vec.x;
	res.y = (vec.y < min) ? min : vec.y;
	res.z = (vec.z < min) ? min : vec.z;
	res.x = (vec.x > max) ? max : vec.x;
	res.y = (vec.y > max) ? max : vec.y;
	res.z = (vec.z > max) ? max : vec.z;
	return (res);
}
