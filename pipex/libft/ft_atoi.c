/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 03:03:27 by snakajim          #+#    #+#             */
/*   Updated: 2024/05/19 22:22:22 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	handle_overflow(const char *str, int sign);

int	ft_space(char c)
{
	if ((c >= 9 && 13 >= c) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned int	n;
	int				result;

	while (ft_space(*str))
		str++;
	if (*str == '-')
		sign = -1;
	else
		sign = 1;
	if (*str == '-' || *str == '+')
		str++;
	n = 0;
	result = (int)handle_overflow(str, sign);
	return (sign * result);
}

static long	handle_overflow(const char *str, int sign)
{
	unsigned long	ret;
	int				digit;
	unsigned long	cutoff;

	ret = 0;
	cutoff = (unsigned long)LONG_MAX;
	while (ft_isdigit(*str))
	{
		digit = *str - '0';
		if (sign == 1 && ret > ((cutoff - digit) / 10))
			return (LONG_MAX);
		if (sign == -1 && ret > ((cutoff + 1 - digit) / 10))
			return (LONG_MIN);
		ret = ret * 10 + digit;
		str++;
	}
	return (ret);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char *str = "1";
// 	char *str2 = " 2";
// 	char *str3 = " 3 2";
// 	char *str4 = "-4";
// 	char *str5 = " -5";
// 	char *str6 = "1/3";
// 	char *str7 = "++7.1415";
// 	char *str8 = "-+2147483649";
// 	char *str9 = "--9223372036854363637353575808";
//     char *str10 ="1844674407370363463695513535616";

// 	printf("%d\n", atoi(str));
// 	printf("%d\n", ft_atoi(str));

// 	printf("%d\n", atoi(str2));
// 	printf("%d\n", ft_atoi(str2));

// 	printf("%d\n", atoi(str3));
// 	printf("%d\n", ft_atoi(str3));

// 	printf("%d\n", atoi(str4));
// 	printf("%d\n", ft_atoi(str4));

// 	printf("%d\n", atoi(str5));
// 	printf("%d\n", ft_atoi(str5));

// 	printf("%d\n", atoi(str6));
// 	printf("%d\n", ft_atoi(str6));

// 	printf("%d\n", atoi(str7));
// 	printf("%d\n", ft_atoi(str7));

// 	printf("%d\n", atoi(str8));
// 	printf("%d\n", ft_atoi(str8));

// 	printf("%d\n", atoi(str9));
// 	printf("%d\n", ft_atoi(str9));

//     printf("%d\n", atoi(str10));
//     printf("%d\n", ft_atoi(str10));

// 	return (0);
// }
