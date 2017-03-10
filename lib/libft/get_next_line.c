/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:36:38 by ple-lez           #+#    #+#             */
/*   Updated: 2016/09/13 08:16:27 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_line_len(t_glob *glob, int const fd)
{
	int				i;

	i = 0;
	while (STR[fd][i] != '\n' && STR[fd][i] != '\0')
		i++;
	return (i);
}

static void			ft_get_line(t_glob *glob, int const fd)
{
	if (STR[fd] == NULL)
		STR[fd] = ft_strnew(1);
	while (!(ft_strchr(STR[fd], '\n')) &&
			(RET = read(fd, BUFF, BUFF_SIZE)) > 0)
	{
		BUFF[RET] = '\0';
		TMP = STR[fd];
		STR[fd] = ft_strjoin(STR[fd], BUFF);
		ft_strdel(&TMP);
	}
	ft_strdel(&BUFF);
}

int					get_next_line(int const fd, char **line)
{
	static t_glob	glob;

	if (fd < 0 || fd > MAX_FD || !(glob.buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	ft_get_line(&glob, fd);
	if (glob.ret == -1)
		return (-1);
	*line = ft_strsub(glob.str[fd], 0, ft_line_len(&glob, fd));
	if (ft_strchr(glob.str[fd], '\n'))
	{
		glob.tmp = glob.str[fd];
		glob.str[fd] = ft_strdup(ft_strchr(glob.str[fd], '\n') + 1);
		ft_strdel(&glob.tmp);
		return (1);
	}
	if (ft_line_len(&glob, fd) > 0)
	{
		glob.str[fd] = glob.str[fd] + ft_line_len(&glob, fd);
		return (1);
	}
	return (0);
}
