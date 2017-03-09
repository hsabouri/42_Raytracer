/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:32:01 by pmartine          #+#    #+#             */
/*   Updated: 2017/03/09 18:59:40 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		print_mesh(t_obj obj) {
	int i;

	i = 0;
	if (obj.type == MESH) {
		while (obj.chld[i].type != BACKSLASH) {
			ft_putstr("Polygon ");
			ft_putnbr(i);
			ft_putchar('\n');
			print_vector(obj.chld[i].vert[0]);
			print_vector(obj.chld[i].vert[1]);
			print_vector(obj.chld[i].vert[2]);
			ft_putchar('\n');
			i++;
		}
	}
	else {
		ft_putendl("Pas un mesh");
		ft_putendl(obj.name);
	}
}

double		ft_min_max(double value, double min, double max)
{
	if (value < min)
		value = min;
	else if (value > max)
		value = max;
	return (value);
}

t_color		sepia(t_color color)
{
	color.r = (color.r * 0.393) + (color.g * 0.769) + (color.b * 0.189);
	color.g = (color.r * 0.349) + (color.g * 0.686) + (color.b * 0.168);
	color.b = (color.r * 0.272) + (color.g * 0.534) + (color.b * 0.131);
	return (color);
}
