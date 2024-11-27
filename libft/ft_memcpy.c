/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 02:15:59 by snakajim          #+#    #+#             */
/*   Updated: 2024/05/18 05:27:03 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (src == NULL && dst == NULL)
		return (0);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n)
	{
		*d = *s;
		n--;
		d++;
		s++;
	}
	return (dst);
}

// int main(void)
// {
// 	char src[] = "Hello, World!";
// 	char dst[20];
// 	ft_memcpy(dst, src, 13);
// 	printf("%s\n", dst);
// 	return (0);
// }