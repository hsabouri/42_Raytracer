/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 21:27:02 by hsabouri          #+#    #+#             */
/*   Updated: 2017/03/08 19:15:26 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <obj.h>

void		check_params(int ac)
{
	if (ac < 2)
	{
		ft_putendl("\x1B[31mERROR\x1B[0m: You must give a file name");
		usage();
		exit(EXIT_FAILURE);
	}
}

static int	is_file(const char *path)
{
	struct stat	path_stat;

	stat(path, &path_stat);
	return (S_ISREG(path_stat.st_mode));
}

int			open_file(char *path)
{
	int	fd;

	printf("%s", path);
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
			{
				printf("access(path, O_RDONLY) == 0\n");
				perror("\x1B[31mERROR\x1B[0m");
			}
		}
		else
		{
			printf("is_file(path)\n");
			ft_putendl("\x1B[31mERROR\x1B[0m: Not a regular file");
		}
	}
	else
	{
		printf("fd = open(path, O_RDONLY)) > 0\n");
		perror("\x1B[31mERROR\x1B[0m");
	}
	exit(EXIT_FAILURE);
}
