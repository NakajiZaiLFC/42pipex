/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 01:30:12 by snakajim          #+#    #+#             */
/*   Updated: 2024/05/18 05:26:32 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (1)
	{
		if (*s == '\0')
			return ;
		ft_putchar_fd(*s, fd);
		s++;
	}
}

// int main(void)
// {
// 	char *s = "Hello, World!";
// 	ft_putstr_fd(s, 1);
// 	return (0);
// }