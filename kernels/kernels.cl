/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernels.cl                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:24:22 by hsabouri          #+#    #+#             */
/*   Updated: 2017/03/02 14:28:16 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kernels.h"

global char *pixel_put(unsigned int x, unsigned int y, global char *img, t_color color)
{
	t_color *t_img = (t_color *)img;

	if (x < LENGTH && y < HEIGHT)
	{
		t_img[y * LENGTH + x] = color;
	}
	return (img);
}

kernel void img_init(global char *img, t_color color)
{
	size_t id = get_global_id(0) + get_global_offset(0);
	size_t x = id % LENGTH;
	size_t y = id / LENGTH;

	pixel_put(x, y, img, color);
}