/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 22:16:45 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/19 11:36:46 by hsabouri         ###   ########.fr       */
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
