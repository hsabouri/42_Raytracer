/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:49:56 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/24 16:02:01 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	error(int code, char *str)
{
	if (code == MALLOC_FAILED)
		perror("\x1B[31mERROR\x1B[0m");
	if (code == PARSING_ERROR)
		ft_putstr("\x1B[31mPARSING ERROR:\x1B[0m ");
	if (str != NULL)
		ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}
