/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:23:33 by ple-lez           #+#    #+#             */
/*   Updated: 2015/11/26 18:24:43 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int		i;
	size_t	len1;

	i = 0;
	len1 = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		s1[len1] = s2[i];
		i++;
		len1++;
	}
	s1[len1] = '\0';
	return (s1);
}
