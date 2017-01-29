/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:15:42 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/29 20:58:19 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	pixel_put(t_env env, int x, int y, t_color color)
{
	int	pos;

	if (x < LENGTH && x >= 0 && y < HEIGHT && y >= 0)
	{
		pos = (x * (env.bpp / 8)) + (y * env.size);
		env.addr[pos + 0] = color.b;
		env.addr[pos + 1] = color.g;
		env.addr[pos + 2] = color.r;
		env.addr[pos + 3] = 0;
	}
}
