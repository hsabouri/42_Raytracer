/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 02:31:15 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/04 12:17:51 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_img 	ui_draw(t_img img, t_compnt compnt)
{
	unsigned int	x;
	unsigned int	y;
	t_color			color;

	y = 0;
	if (compnt.status == IDLE || compnt.status == ACTION)
		color = compnt.bg;
	if (compnt.status == HOVER)
		color = compnt.bg_hv;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < LENGTH)
		{
			img = pixel_put(img, x, y, (t_color){0, 0, 0, 255});
			x++;
		}
		y++;
	}
	y = 0;
	while (y < (unsigned int)compnt.h)
	{
		x = 0;
		while (x < (unsigned int)compnt.w)
		{
			img = pixel_put(img, x + compnt.x, y + compnt.y, color);
			x++;
		}
		y++;
	}
	if (compnt.draw_img == 1)
		img = merge_img(img, compnt.img, compnt.x, compnt.y);
	return (img);
}
