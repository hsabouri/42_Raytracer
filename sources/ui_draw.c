/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 02:31:15 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/07 13:51:20 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_ui 	*ui_draw(t_ui *ui, t_compnt compnt)
{
	int		x;
	int		y;
	t_color	color;

	if (compnt.status == IDLE || compnt.status == ACTION)
		color = compnt.bg;
	if (compnt.status == HOVER)
		color = compnt.bg_hv;
//	ui->lay1 = init_img(ui->lay1, (t_color){0, 0, 0, 255});
//	ui->lay2 = init_img(ui->lay2, (t_color){0, 0, 0, 255});
	y = 0;
	while (y < compnt.h)
	{
		x = 0;
		while (x < compnt.w)
		{
			ui->lay1 = pixel_put(ui->lay1, x + compnt.x, y + compnt.y, color);
			x++;
		}
		y++;
	}
	if (compnt.draw_img == 1)
		ui->lay2 = merge_img(ui->lay2, compnt.img, compnt.x, compnt.y);
	return (ui);
}
