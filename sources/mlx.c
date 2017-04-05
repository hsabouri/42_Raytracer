/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:15:42 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/05 15:42:20 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int				exit_clean(t_env *env)
{
	if (env->drawing)
		pthread_cancel(env->render_thread);
	exit(EXIT_SUCCESS);
}

t_img			*create_img(t_img *res, int width, int height, void *mlx)
{
	if (!(res->img = mlx_new_image(mlx, width, height)))
		c_error("mlx_new_image, failed to create mlx image(s)->", 0);
	if (!(res->addr = mlx_get_data_addr(res->img, &res->bpp,\
	&res->size, &res->endian)))
		c_error("mlx_get_data_addr, failed to create mlx image(s)->", 0);
	res->width = width;
	res->height = height;
	return (res);
}

t_img			init_img(t_img img, t_color color)
{
	int i;

	i = 0;
	while (i < img.width * img.height)
	{
		img = pixel_put(img, i % img.width, i / img.width, color);
		i++;
	}
	return (img);
}

t_img			pixel_put(t_img img, int x, int y, t_color color)
{
	if (x < img.width && y < img.height)
		((t_color *)(img.addr))[x + y * img.width] = color;
	return (img);
}
