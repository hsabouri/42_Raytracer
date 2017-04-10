/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:46:50 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/10 13:45:48 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_img			merge_img(t_img bg, t_img fg, int x, int y)
{
	int				c_x;
	int				c_y;
	const t_color	*c_fg = (t_color *)fg.addr;

	c_y = 0;
	while (c_y < fg.height)
	{
		c_x = 0;
		while (c_x < fg.width)
		{
			bg = pixel_put(bg, x + c_x, y + c_y, c_fg[c_y * fg.width + c_x]);
			c_x++;
		}
		c_y++;
	}
	return (bg);
}
