/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:20:20 by ple-lez           #+#    #+#             */
/*   Updated: 2015/12/11 20:51:17 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *restrict dst, const void *restrict src,
		int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_cp;
	unsigned char	*src_cp;
	unsigned char	fnd;

	i = 0;
	dst_cp = (unsigned char *)dst;
	src_cp = (unsigned char *)src;
	fnd = (unsigned char)c;
	while (i < n)
	{
		dst_cp[i] = src_cp[i];
		if (src_cp[i] == fnd)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
