/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:15:42 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/28 19:32:43 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	pixel_put(t_env env, int x, int y, t_color color)
{
	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
		((t_color *)(env.img))[y * WIDTH + x] = color;
}
