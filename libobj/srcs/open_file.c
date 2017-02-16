/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 21:27:02 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/16 13:56:27 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj.h"

int	open_file(const char *filename)
{
	int	fd;

	if ((fd = open(filename, O_RDONLY)))
		ft_putendl("\x1B[32mLOG:\x1B[0m File opened successfully.");
	else
		ft_putendl("\x1B[31mLOG:\x1B[0m Failed to open file.");
	return (fd);
}
