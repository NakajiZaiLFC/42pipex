/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:28:07 by snakajim          #+#    #+#             */
/*   Updated: 2024/05/19 22:30:37 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	char	*result;
	size_t	i;

	result = NULL;
	i = 0;
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	count = ft_strlen(&s[start]);
	if (count >= len)
		result = (char *)malloc(len + 1);
	else if (count < len)
		result = (char *)malloc(count + 1);
	if (result == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

// #include <stdio.h>
// #include <limits.h>
// int	main(void)
// {
// 	char	*str;
// 	char	*result;

// 	str = "Hello World";
// 	result = ft_substr(str, 6, 5);
// 	printf("%s\n", result);
// 	result = ft_substr(str, 0, 5);
// 	printf("%s\n", result);
// 	result = ft_substr(str, 0, 0);
// 	printf("%s\n", result);
// 	result = ft_substr(str, 0, INT_MAX);
// 	printf("%s\n", result);
// 	result = ft_substr(str, INT_MAX, INT_MIN);
// 	printf("%s\n", result);
// 	return (0);
// }