/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 18:32:02 by ple-lez           #+#    #+#             */
/*   Updated: 2015/12/21 16:49:26 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_nb_tenth(int n, size_t *len, int *fct)
{
	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*fct = 1;
	while ((n / *fct) < -9)
	{
		*fct *= 10;
		*len += 1;
	}
}

char			*ft_itoa(int n)
{
	size_t		len;
	size_t		i;
	char		*str;
	int			fct;

	ft_nb_tenth(n, &len, &fct);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
	}
	if (n > 0)
		n = -n;
	while (fct >= 1)
	{
		str[i] = -((n / fct) % 10) + '0';
		fct /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}
