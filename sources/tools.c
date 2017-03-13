/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:32:01 by pmartine          #+#    #+#             */
/*   Updated: 2017/03/13 18:51:16 by pmartine         ###   ########.fr       */
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

t_color		filters(t_color c, t_env env)
{
	int		i;

	i = (c.r + c.g + c.b) / 3;
	if (env.filter == NB)
		return ((t_color){i,i,i,c.a});
	else if (env.filter == SEPIA)
	{
		c.r = (c.r * 0.393) + (c.g * 0.769) + (c.b * 0.189);
	   	c.g = (c.r * 0.349) + (c.g * 0.686) + (c.b * 0.168);
	   	c.b = (c.r * 0.272) + (c.g * 0.534) + (c.b * 0.131);
		return (c);
	}
	else if (env.filter == BLUE)
		return ((t_color){255,i,i,c.a});
	else if (env.filter == GREEN)
		return ((t_color){i,255,i,c.a});
	else if (env.filter == RED)
		return ((t_color){i,i,255,c.a});
	else if (env.filter == NEG)
		return ((t_color){255 - c.r, 255 - c.g, 255 - c.b, c.a});
	else
		return (c);
}
