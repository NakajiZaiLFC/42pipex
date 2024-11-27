/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:05:30 by snakajim          #+#    #+#             */
/*   Updated: 2024/05/18 05:27:13 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (s >= d || d >= s + n)
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		d += n - 1;
		s += n - 1;
		while (n--)
		{
			*d-- = *s--;
		}
	}
	return (dst);
}

// int main(void)
// {
// 	char src[] = "Hello, World!";
// 	char dst[20];
// 	ft_memmove(dst, src, 13);
// 	printf("%s\n", dst);
// 	return (0);
// }