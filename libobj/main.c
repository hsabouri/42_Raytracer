/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2001/09/11 14:07:49 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/19 11:15:06 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <obj.h>

int main(int ac, char **av)
{
	int		fd;
	t_obj	*objs;
	size_t i = 0;

	check_params(ac, av);
	fd = open_file(av[1]);
	objs = parse(fd);
	while (objs[i].type != BACKSLASH)
	{
		printf("Object number : %zu\n	Object name : %s\n", i, objs[i].name);
		printf("	Object color : %d %d %d\n",
				objs[i].mat.rgb.r,
				objs[i].mat.rgb.g,
				objs[i].mat.rgb.b);
		printf("	Object position : %f %f %f\n",
				objs[i].pos.x,
				objs[i].pos.y,
				objs[i].pos.z);
		i++;
	}
	return (0);
}
