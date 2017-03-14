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

#include <kernels.h>

char *pixel_put(unsigned int x, unsigned int y, char *img, t_color color)
{
	if (x < WIDTH && x >= 0 && y < LENGTH && y >= 0)
	{
		(t_color *)img[y * WIDTH + x] = color;
	}
}

__kernel void img_init(char *img, t_color color)
{
	size_t id = get_global_id(0) + get_global_offset(0);
	size_t x = id % LENGTH;
	size_t y = id / LENGTH;

	img = pixel_put(unsigned int x, unsigned int y, char *img, t_color color);
}