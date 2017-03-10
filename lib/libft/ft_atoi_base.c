/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:00:27 by ple-lez           #+#    #+#             */
/*   Updated: 2015/12/18 16:53:58 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Convert a string of base b in an integer of base 10;
** If the base is < 2, the function returns 0,
** Base 1 is already non-sens, but base -1's more;
** If the base is > 36, the function returns 0,
** After 36, we run out of characters to print a digit;
** If the integer is neg, the function returns 0;
** If Base is 10, better use ft_atoi (handle negatives case)
*/

#include "libft.h"

static int	ft_convert(char *str, int i, int b)
{
	int	n;

	n = 0;
	while (str[i] && ft_isalnum((int)str[i]))
	{
		n *= b;
		if (ft_isdigit((int)str[i]))
		{
			n += (int)(str[i] - '0');
		}
		else if (ft_isalnum((int)str[i]))
		{
			n += (int)(str[i] - 55);
		}
		i++;
	}
	return (n);
}

int			ft_atoi_base(char *str, int b)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || b < 2 || b > 36)
		return (0);
	if (str[i] == '+')
		i++;
	return (ft_convert(str, i, b));
}
