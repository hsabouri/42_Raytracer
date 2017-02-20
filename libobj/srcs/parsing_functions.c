/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 22:16:45 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/19 18:55:59 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <obj.h>

t_vec4	parse_vec(char *str)
{
	t_vec4 vector;

	vector.x = ft_atof(str);
	while (*str != ' ' && *str)
		str++;
	vector.y = ft_atof(str);
	str++;
	while (*str != ' ' && *str)
		str++;
	vector.z = ft_atof(str);
	vector.w = get_vector_len(vector);
	return (vector);
}

double	parse_double(char *str)
{
	double res;

	res = ft_atof(str);
	return (res);
}

t_color	parse_color(char *str)
{
	t_color	color;
	int		tmp;

	tmp = ft_atoi(str);
	if (tmp > 255)
		tmp = 255;
	color.r = tmp;
	while (*str != ' ' && *str)
		str++;
	tmp = ft_atoi(str);
	if (tmp > 255)
		tmp = 255;
	color.g = tmp;
	str++;
	while (*str != ' ' && *str)
		str++;
	tmp = ft_atoi(str);
	if (tmp > 255)
		tmp = 255;
	color.b = tmp;
	color.a = 0;
	return (color);
}
