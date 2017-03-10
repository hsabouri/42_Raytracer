/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:52:16 by ple-lez           #+#    #+#             */
/*   Updated: 2015/12/09 16:59:38 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nb_wrd(const char *s, char c)
{
	int		nb_wrd;
	int		swt;

	nb_wrd = 0;
	swt = 0;
	while (*s != '\0')
	{
		if (swt == 1 && *s == c)
			swt = 0;
		if (swt == 0 && *s != c)
		{
			swt = 1;
			nb_wrd++;
		}
		s++;
	}
	return (nb_wrd);
}

static int		ft_wrdlen(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		nb_word;
	int		i;

	i = 0;
	nb_word = ft_nb_wrd(s, c);
	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_nb_wrd(s, c) + 1));
	if (res == NULL)
		return (NULL);
	while (nb_word > 0)
	{
		while (*s == c && *s != '\0')
			s++;
		res[i] = ft_strsub(s, 0, ft_wrdlen(s, c));
		if (res[i] == NULL)
			return (NULL);
		s = s + ft_wrdlen(s, c);
		i++;
		nb_word--;
	}
	res[i] = NULL;
	return (res);
}
