/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:46:50 by ple-lez           #+#    #+#             */
/*   Updated: 2017/03/16 16:54:05 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_img			create_xpm_img(char *path, t_env env)
{
	t_img		res;

	if (!(res.img = mlx_xpm_file_to_image(env.mlx, path,
				&res.width, &res.height)))
		exit(0);
	res.addr = mlx_get_data_addr(res.img, &res.bpp, &res.size, &res.endian);
	res.bpp /= 8;
	res.width = res.size / res.bpp;
	res.height = res.height / res.bpp;
	return (res);
}
