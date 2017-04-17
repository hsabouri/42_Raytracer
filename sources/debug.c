/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:24:22 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/13 18:04:02 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		c_log(char *str)
{
	ft_putstr("\x1b[32mLOG:\x1b[0m ");
	ft_putendl(str);
}

void		error(int code, char *str)
{
	if (code == MALLOC_FAILED)
		perror("\x1B[31mERROR\x1B[0m");
	if (code == PARSING_ERROR)
		ft_putstr("\x1B[31mPARSING ERROR:\x1B[0m ");
	if (str != NULL)
	{
		ft_putstr("\x1B[31mERROR: \x1B[0m");
		ft_putendl_fd(str, 2);
	}
	exit(EXIT_FAILURE);
}

void		c_error(char *str, int code)
{
	ft_putstr("\x1b[31mERROR ");
	ft_putnbr(code);
	ft_putstr("\x1b[0m: ");
	ft_putendl(str);
	perror("perror() message");
	exit(EXIT_FAILURE);
}

static int	is_file(const char *path)
{
	struct stat	path_stat;

	stat(path, &path_stat);
	return (S_ISREG(path_stat.st_mode));
}

int			c_open_file(char *path)
{
	int	fd;
	int err;

	err = 0;
	if ((fd = open(path, O_RDONLY)) > 0)
	{
		if ((err = is_file(path)))
		{
			if ((err = access(path, O_RDONLY) == 0))
			{
				c_log("File opened successfully.");
				return (fd);
			}
			else
				c_error("Can't have access to the file.", err);
		}
		else
			c_error("Not a file.", err);
	}
	else
		c_error("Can't open file.", err);
	exit(EXIT_FAILURE);
}
