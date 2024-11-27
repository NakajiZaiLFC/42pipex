/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:38:30 by snakajim          #+#    #+#             */
/*   Updated: 2024/05/19 22:22:47 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (len > i)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
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
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*src;
// 	char	*dst;

// 	src = "";
// 	dst = ft_strdup(src);
// 	printf("%s\n", dst);
// 	dst = strdup(src);
// 	printf("%s\n", dst);
// 	src = "Hello World!";
// 	dst = ft_strdup(src);
// 	printf("%s\n", dst);
// 	dst = strdup(src);
// 	printf("%s\n", dst);
// 	return (0);
// }
