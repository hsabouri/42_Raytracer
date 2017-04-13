/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 21:27:02 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/13 17:51:45 by qduperon         ###   ########.fr       */
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

t_img		create_xpm_img(char *path, t_env env)
{
	t_img		res;

	res.type = IMAGE;
	res.img = mlx_xpm_file_to_image(env.mlx, path, &res.width, &res.height);
	res.addr = mlx_get_data_addr(res.img, &res.bpp, &res.size, &res.endian);
	return (res);
}

t_img		parse_asset(char *path, t_env env)
{
	int fd;

	if ((fd = open(path, O_RDONLY)) > 0)
	{
		if (is_file(path))
		{
			if (access(path, O_RDONLY) == 0)
			{
				ft_putstr("\x1B[32mLOG\x1B[0m: Asset ");
				ft_putstr(path);
				ft_putendl(" added");
				close(fd);
				return (create_xpm_img(path, env));
			}
			else
				perror("\x1B[31mERROR\x1B[0m");
		}
		else
			ft_putendl("\x1B[31mERROR\x1B[0m: Not a regular file");
	}
	else
		perror("\x1B[31mERROR\x1B[0m");
	ft_putstr(path);
	ft_putendl(": asset can't be charged");
	exit(EXIT_FAILURE);
}

int			open_file(char *path)
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
