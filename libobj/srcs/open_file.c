/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 21:27:02 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/17 11:26:37 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj.h"

static int	is_file(const char *path)
{
	struct stat	path_stat;
	stat(path, &path_stat);
	return (S_ISREG(path_stat.st_mode));
}

int			open_file(const char *path)
{
	int	fd;

	if ((fd = open(path, O_RDONLY)) > 0)
	{
		if (is_file(path))
		{
			if (access(path, O_RDONLY) == 0)
			{
				ft_putendl("\x1B[32mLOG\x1B[0m: File opened successfully");
				return (fd);
			}
			else
				perror("\x1B[31mERROR\x1B[0m");
		}
		else
			ft_putendl("\x1B[31mERROR\x1B[0m: Not a regular file");
	}
	else
		perror("\x1B[31mERROR\x1B[0m");
	exit(EXIT_FAILURE);
}
