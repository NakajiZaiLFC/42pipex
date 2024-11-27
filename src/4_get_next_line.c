/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_get_next_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:34:20 by snakajim          #+#    #+#             */
/*   Updated: 2024/11/24 10:37:45 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_string	ret;
	int			c;

	ret = (t_string){NULL, 0, 0};
	while (1)
	{
		c = ft_getc(fd);
		if (c == -2)
			return (str_free(ret));
		if (c == EOF)
			break ;
		c = ft_putc(&ret, c);
		if (c == -1)
			return (str_free(ret));
		if (c == '\n')
			break ;
	}
	if (ret.len > 0)
		c = ft_putc(&ret, '\0');
	if (c == -1)
		return (str_free(ret));
	return (ret.str);
}

int	ft_getc(int fd)
{
	static char		buf[BUFFER_SIZE];
	static char		*bufp;
	static ssize_t	n;

	if (n == 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
		{
			n = 0;
			return (-2);
		}
		else if (n == 0)
			return (EOF);
		bufp = buf;
	}
	n--;
	return ((unsigned char)*bufp++);
}

int	ft_putc(t_string *str, char c)
{
	char	*new_str;
	size_t	capa;

	if (str->str == NULL || str->len + 1 > str->capa)
	{
		if (str->capa > 0)
			capa = str->capa * 2;
		else
			capa = 2;
		new_str = malloc(capa);
		if (new_str == NULL)
			return (-1);
		ft_memcpy(new_str, str->str, str->len);
		free(str->str);
		str->str = new_str;
		str->capa = capa;
	}
	str->str[str->len++] = c;
	return (c);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*buf;
	unsigned char	*str;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	buf = (unsigned char *)dst;
	str = (unsigned char *)src;
	while (i < n)
	{
		buf[i] = str[i];
		i++;
	}
	return (buf);
}

char	*str_free(t_string ret)
{
	free(ret.str);
	return (NULL);
}
