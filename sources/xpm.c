/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:46:50 by ple-lez           #+#    #+#             */
/*   Updated: 2017/03/16 18:01:54 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_img			create_xpm_img(char *path, t_env env)
{
	t_img		res;

	res.img = mlx_xpm_file_to_image(env.mlx, path, &res.width, &res.height);
	res.addr = mlx_get_data_addr(res.img, &res.bpp, &res.size, &res.endian);
	res.bpp /= 8;
	res.width = res.size / res.bpp;
	res.height = res.size / res.bpp;
	return (res);
}
