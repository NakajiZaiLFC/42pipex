/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:55:47 by snakajim          #+#    #+#             */
/*   Updated: 2024/05/18 06:35:54 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		((char *)b)[count] = c;
		count++;
	}
	return (b);
}

// int	main(void)
// {
// 	char	str[50] = "Hello, World!";
// 	ft_memset(str, 'a', 13);
// 	printf("%s\n", str);
// 	return (0);
// }