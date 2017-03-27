/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:15:42 by hsabouri          #+#    #+#             */
/*   Updated: 2017/03/19 13:05:24 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int				exit_clean(t_env *env)
{
	if (env->drawing)
		pthread_cancel(env->render_thread);
	exit(EXIT_SUCCESS);
}

t_img			init_img(t_img img, t_color color)
{
	int i;

	i = 0;
	while (i < img.width * img.height)
	{
		img = pixel_put(img, i % LENGTH, i / LENGTH, color);
		i++;
	}
	return (img);
}

t_img			pixel_put(t_img img, unsigned int x, unsigned int y, t_color color)
{
	if (x < LENGTH && y < HEIGHT)
		((t_color *)(img.addr))[x + y * LENGTH] = color;
	return (img);
}
