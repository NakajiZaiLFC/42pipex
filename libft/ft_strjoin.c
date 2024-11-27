/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:07:41 by snakajim          #+#    #+#             */
/*   Updated: 2024/05/18 05:43:49 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*strlen;
	unsigned int	sum;
	unsigned int	count;

	count = 0;
	sum = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	sum = ft_strlen(s1)+ft_strlen(s2);
	strlen = (char *)malloc(sum + 1);
	if (strlen == NULL)
		return (NULL);
	sum = 0;
	while (s1[count] != '\0')
	{
		strlen[count] = s1[count];
		count++;
	}
	while (s2[sum] != '\0')
		strlen[count++] = s2[sum++];
	strlen[count] = '\0';
	return (strlen);
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

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;
// 	char	*result;

// 	s1 = "Hello";
// 	s2 = " World!";
// 	result = ft_strjoin(s1, s2);
// 	printf("%s\n", result);
// 	return (0);
// }