/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 01:31:36 by snakajim          #+#    #+#             */
/*   Updated: 2024/05/19 22:34:46 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	size_t	len;
	char	*ret;

	if (s == NULL)
		return (NULL);
	len = (unsigned int)ft_strlen((char *)s);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		ret[index] = f(index, s[index]);
		index++;
	}
	ret[index] = '\0';
	return (ret);
}
