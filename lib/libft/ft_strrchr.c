/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:43:14 by ple-lez           #+#    #+#             */
/*   Updated: 2015/11/27 13:54:50 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*rst;

	rst = (char *)s;
	len = (int)ft_strlen(s);
	while (len >= 0 && rst[len] != (unsigned char)c)
		len--;
	if (rst[len] == (unsigned char)c)
		return (&rst[len]);
	return (NULL);
}
