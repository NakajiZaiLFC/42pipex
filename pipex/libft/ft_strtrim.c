/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 00:51:55 by snakajim          #+#    #+#             */
/*   Updated: 2024/05/18 06:07:44 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_matched(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen((char *)set))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	process_start(char **s1, char const *set, size_t *len)
{
	while (1)
	{
		if (**s1 == '\0')
			return (0);
		if (!is_matched(**s1, set))
			break ;
		(*len)--;
		(*s1)++;
	}
	return (1);
}

static void	process_end(char *s1, char const *set, size_t *len)
{
	while (1)
	{
		if (!is_matched(*(s1 + *len - 1), set))
			break ;
		(*len)--;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*trimmed_str;
	char	*start;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen((char *)s1);
	if (!process_start((char **)&s1, set, &len))
		return (ft_strdup(""));
	start = (char *)s1;
	process_end((char *)s1, set, &len);
	trimmed_str = (char *)malloc(sizeof(char) * (len + 1));
	if (trimmed_str == NULL)
		return (NULL);
	ft_memcpy(trimmed_str, start, len);
	*(trimmed_str + len) = '\0';
	return (trimmed_str);
}
