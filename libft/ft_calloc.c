/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 01:04:58 by snakajim          #+#    #+#             */
/*   Updated: 2024/05/19 22:22:55 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count && size > SIZE_MAX / count)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}

// int main(void)
// {
//     size_t count = (size_t)SIZE_MAX / 10 + (size_t)1;
//     size_t size = 10;
//     void *ptr = ft_calloc(count, size);
//     void *ptr2 = calloc(count, size);

//     if (ptr == NULL || ptr2 == NULL)
//     {
//         printf("Memory allocation failed\n");
//         return (1);
//     }

//     size_t allocated_size_ft_calloc = count * size;
//     size_t allocated_size_calloc = count * size;

//     if (allocated_size_ft_calloc != allocated_size_calloc)
//     {
//         printf("Different sizes of memory allocated\n");
//         return (1);
//     }

//     printf("Memory allocation successful\n");

//     free(ptr);
//     free(ptr2);

//     return (0);
// }
