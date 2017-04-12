/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:15:42 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/12 13:54:09 by hsabouri         ###   ########.fr       */
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

t_env			*del_square(t_env *env, int x, int y, int side)
{
	int		c_x;
	int		c_y;
	t_img	lay1;
	t_img	bg;
	t_color	color;
	
	lay1 = env->ui->lay2;
	bg = env->img;
	c_x = 0;
	while (c_x < side)
	{
		c_y = 0;
		while (c_y < side)
		{
			color = ((t_color *)bg.addr)[(y + c_y) * bg.width + c_x + x];
			lay1 = pixel_put(lay1, x + c_x, y + c_y, color);
			c_y++;
		}
		c_x++;
	}
	return (env);
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
