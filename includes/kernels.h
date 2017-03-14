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
# include "struct.h"
# include "defines.h"

void pixel_put(unsigned int x, unsigned int y, char *img, t_color color);

#endif