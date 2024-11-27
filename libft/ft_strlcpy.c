/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 03:28:32 by snakajim          #+#    #+#             */
/*   Updated: 2024/05/11 02:02:11 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen((char *)src);
	if (dstsize <= 0)
		return (len);
	dstsize -= 1;
	i = 0;
	while (dstsize)
	{
		if (src[i] == '\0')
			break ;
		dst[i] = src[i];
		dstsize--;
		i++;
	}
	dst[i] = '\0';
	return (len);
}

// size_t	ft_strlen(const char *s)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[len] != '\0')
// 	{
// 		len++;
// 	}
// 	return (len);
// }
