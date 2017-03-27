/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:02:38 by hsabouri          #+#    #+#             */
/*   Updated: 2016/12/03 13:49:31 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static t_img	bhv1(t_img image, t_line line, t_color color)
{
	int i;

	i = 1;
	while (i <= line.dx)
	{
		line.x += line.xinc;
		line.cumul += line.dy;
		if (line.cumul >= line.dx)
		{
			line.cumul -= line.dx;
			line.y += line.xinc;
		}
		image = pixel_put(image, line.x, line.y, color);
		i++;
	}
	return (image);
}

static t_img	bhv2(t_img image, t_line line, t_color color)
{
	int i;

	i = 1;
	while (i <= line.dy)
	{
		line.y += line.yinc;
		line.cumul += line.dx;
		if (line.cumul >= line.dy)
		{
			line.cumul -= line.dy;
			line.x += line.xinc;
		}
		image = pixel_put(image, line.x, line.y, color);
		i++;
	}
	return (image);
}

t_img			line(t_img image, t_pix start, t_pix end, t_color color)
{
	t_line	line;

	if (start.x > end.x)
		ft_swap(&(start.x), &(end.x));
	if (start.y > end.y)
		ft_swap(&(start.y), &(end.y));
	line.x = start.x;
	line.y = start.y;
	line.dx = (end.x - start.x > 0) ? (end.x - start.x) : -(end.x - start.x);
	line.dy = (end.y - start.y > 0) ? (end.y - start.y) : -(end.y - start.y);
	line.xinc = (end.x - start.x > 0) ? 1 : -1;
	line.yinc = (end.y - start.y > 0) ? 1 : -1;
	image = pixel_put(image, line.x, line.y, color);
	if (line.dx > line.dy)
		image = bhv1(image, line, color);
	else
		image = bhv2(image, line, color);
	return (image);
}
