/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorria <jelorria@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:55:05 by jelorria          #+#    #+#             */
/*   Updated: 2022/04/05 17:42:11 by jelorria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_strdup(char *s1)
{
	char				*dest;
	unsigned char		*ptr;
	const unsigned char	*ptr2;
	size_t				n;

	dest = (char *)malloc(sizeof(char) * ft_strlen(s1, 1) + 1);
	if (!dest)
		return (NULL);
	ptr = (unsigned char *)dest;
	ptr2 = (unsigned char *)s1;
	n = ft_strlen(s1, 1);
	while (n-- > 0)
		*(ptr++) = *(ptr2++);
	*(dest + ft_strlen(s1, 1)) = '\0';
	return (dest);
}

char	*end_line(char **holder2, char *buf)
{
	int		n;
	char	*line;

	n = ft_strlen(*holder2, 2);
	line = (char *)malloc((n + 1) * sizeof(char));
	ft_strlcpy(line, *holder2, n + 1);
	*holder2 = ft_strtrim(*holder2, line);
	free(buf);
	return (line);
}

static char	*update_holder(char **holder, char *buf, size_t a)
{
	char	*temp;

	if (a <= 1 && a > 0)
	{
		if (ft_strlen(*holder, 1) > 0)
		{
			temp = (char *)malloc(sizeof(char) * (a + 1));
			ft_strlcpy(temp, buf, a + 1);
			*holder = ft_strjoin(*holder, temp);
			free(temp);
		}
		else
		{
			free(*holder);
			*holder = (char *)malloc(sizeof(char) * a + 1);
			ft_strlcpy(*holder, buf, a + 1);
		}
	}
	return (*holder);
}

char	*update_line(char **holder, char *buf)
{
	char	*line;

	if (ft_strlen(*holder, 1) > 0)
	{
		line = (char *)malloc(sizeof(char) * ft_strlen(*holder, 1) + 1);
		ft_strlcpy(line, *holder, ft_strlen(*holder, 1) + 1);
		free(buf);
		free(*holder);
		*holder = NULL;
		return (line);
	}
	free(buf);
	free(*holder);
	*holder = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*holder;
	size_t		a;

	if (fd < 0 || 1 <= 0)
		return (NULL);
	buf = (char *)malloc((1 + 1) * sizeof(char));
	if (!holder)
		holder = ft_strdup("");
	while (ft_strlen(holder, 2) == 0)
	{
		a = read(fd, buf, 1);
		if (a == 0 || (int)a == -1)
			return (update_line(&holder, buf));
		buf[a] = '\0';
		holder = update_holder(&holder, buf, a);
		if (!holder)
			return (NULL);
	}
	line = end_line(&holder, buf);
	return (line);
}
