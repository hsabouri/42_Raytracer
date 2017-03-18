/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 22:16:45 by hsabouri          #+#    #+#             */
/*   Updated: 2017/03/07 12:02:30 by ple-lez          ###   ########.fr       */
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
	vector.w = 1;
	return (vector);
}

t_quat	parse_quat(char *str, t_obj *obj)
{
	t_quat	res;
	double	r;
	t_vec4	axis;

	r = parse_double(str);
	while (!ft_isspace(*str))
		str++;
	axis = parse_vec(str);
	res = new_quat(r, axis);
	obj->inv = get_inverse(res);
	return (res);
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
