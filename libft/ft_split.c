/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 01:24:35 by snakajim          #+#    #+#             */
/*   Updated: 2024/05/18 06:54:11 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*free_array(char **arr, size_t i)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
	return (NULL);
}

static int	count_words(char const *str, char c)
{
	size_t	i;
	int		cnt;

	i = 0;
	cnt = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			cnt++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (cnt);
}

static char	*ft_strndup(const char *src, size_t n)
{
	size_t	i;
	char	*dup;

	if (!src)
		return (NULL);
	dup = (char *)malloc((n + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		i;
	const char	*start;

	if (!s || count_words(s, c) == -1)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		start = s;
		while (*s != c && *s)
			s++;
		result[i] = ft_strndup(start, s - start);
		if (!result[i++])
			return (free_array(result, i - 1), NULL);
	}
	result[i] = NULL;
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main (void)
// {
// 	char *str = "Hello World";
// 	char **ret = ft_split(str, ' ');
// 	int i = 0;
// 	while (ret[i] != NULL)
// 	{
// 		printf("%s\n", ret[i]);
// 		i++;
// 	}
// 	char *str2 = "Hello World";
// 	char **ret2 = ft_split(str2, 'o');
// 	int j = 0;
// 	while (ret2[j] != NULL)
// 	{
// 		printf("%s\n", ret2[j]);
// 		j++;
// 	}

// 	char *str3 = "Hello World";
// 	char **ret3 = split(str3, 'l');
// 	int k = 0;
// 	while (ret3[k] != NULL)
// 	{
// 		printf("%s\n", ret3[k]);
// 		k++;
// 	}
// 	return (0);
// }
