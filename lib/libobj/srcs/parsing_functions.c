/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <hsabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 22:16:45 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/06 15:52:20 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <obj.h>

t_ttype	type_of_objs(char *str)
{
	t_ttype	type;

	if (ft_strnstr(str, "NOISE", 5))
		type = NOISE;
	if (ft_strnstr(str, "WOOD", 4))
		type = WOOD;
	if (ft_strnstr(str, "MARBLE", 6))
		type = MARBLE;
	if (ft_strnstr(str, "BRICKS", 6))
		type = BRICKS;
	if (ft_strnstr(str, "CHECKER", 7))
		type = CHECKER;
	return (type);
}

t_vec4	parse_vec(char *str)
{
	t_vec4 vector;

	vector.x = ft_atof(str);
	while (!ft_isspace(*str) && *str)
		str++;
	vector.y = ft_atof(str);
	str++;
	while (*str != ' ' && *str)
		str++;
	vector.z = ft_atof(str);
	vector.w = 1;
	return (vector);
}

t_quat	parse_quat(char *str, t_quat *inv)
{
	t_quat	res;
	t_vec4	axis;

	axis.x = parse_double(str);
	while (!ft_isspace(*str) && *str)
		str++;
	while (ft_isspace(*str) && *str)
		str++;
	axis.y = parse_double(str);
	while (!ft_isspace(*str) && *str)
		str++;
	while (ft_isspace(*str) && *str)
		str++;
	axis.z = parse_double(str);
	res = new_quat(M_PI / 180, axis);
	if (inv)
		*inv = get_inverse(res);
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
