/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procedural.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:58:22 by ple-lez           #+#    #+#             */
/*   Updated: 2017/03/19 15:07:35 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#define WHITE 0xffffff
#define RED 0xff0000

unsigned int		bricks(t_vec4 pos)
{
	int				tx;
	int				ty;
	int				odd;
	int				edge;

	tx = (int)((double)10 * pos.x);
	ty = (int)((double)10 * pos.y);
	odd = (tx & 0x01) == (ty & 0x01);
	edge = ((10 * pos.x - tx < 0.1) && odd) || (10 * pos.y - ty < 0.1);
	return (edge ? WHITE : RED);
}

t_color				get_pixel_procedure(t_obj obj, t_vec4 pos)
{
	unsigned int	tmp;
	t_color			res;

	if (obj.mat.texture.type == BRICKS)
		tmp = bricks(pos);
	else
		return (res = (t_color){0, 0, 0, 0});
	res = uint_to_color(tmp);
	return (res);
}
