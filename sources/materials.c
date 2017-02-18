/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 00:13:41 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/19 00:21:26 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_mat		new_material(t_color rgb, t_vec4 coef, double rf, double rr)
{
	t_mat	res;

	res = (t_mat){rgb, coef, rf, rr};
	return (res);
}
