/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2001/09/11 14:07:49 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/20 19:45:46 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <obj.h>

int main(int ac, char **av)
{
	int		fd;
	t_obj	*objs;
	size_t i = 0;

	check_params(ac);
	fd = open_file(av[1]);
	objs = parse(fd);
	display_objs(objs);
	return (0);
}
