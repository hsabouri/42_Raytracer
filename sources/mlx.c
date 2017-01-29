/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:15:42 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/29 18:53:38 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	pixel_put(t_env env, int x, int y, t_color color)
{
	int	pos;

	pos = (x * (env.bpp / 8)) + (y * env.size);
	env.addr[pos + 0] = color.b;
	env.addr[pos + 1] = color.g;
	env.addr[pos + 2] = color.r;
}
