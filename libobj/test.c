/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 09:58:17 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/17 11:26:36 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/obj.h"

int main(int ac, char **av)
{
	int	fd;

	if (ac < 2)
		ft_putendl_fd("\x1B[32mERROR: You must give a filename\x1B[0m", 2);
	fd = open_file(av[1]);
	return (0);	
}
