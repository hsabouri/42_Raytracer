/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernels.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:24:22 by hsabouri          #+#    #+#             */
/*   Updated: 2017/03/02 14:28:16 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KERNEL_H
# define KERNEL_H
# include "defines.h"
# include "struct.h"

global char *pixel_put(unsigned int x, unsigned int y, global char *img,\
	t_color color);

#endif