/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:16:04 by paapahid          #+#    #+#             */
/*   Updated: 2025/11/26 23:10:07 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	unsigned char	j;

	if (!s)
		return (NULL);
	j = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == j)
			return ((char *)s);
		s++;
	}
	if (j == '\0')
		return ((char *)s);
	else
		return (NULL);
}

static char	*ft_complete_line(char *rest)
{
	char	*line;
	int		i;

	i = 0;
	if ((!rest) || !rest[0] )
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		i++;
	line = ft_substr_gnl(rest, 0, i);
	return (line);
}

static char	*ft_clean_rest(char *rest)
{
	char	*clean;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!rest)
		return (NULL);
	while (rest[j])
		j++;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		i++;
	if (!rest[i])
		return (free(rest), NULL);
	clean = ft_substr_gnl(rest, i, j - i);
	free(rest);
	rest = NULL;
	return (clean);
}

static char	*ft_readfile_gnl(int fd, char *rest)
{
	char	*buffer;
	int		bytes;

	bytes = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(rest) , NULL);
	while ((bytes > 0) && (!ft_strchr(rest, '\n')))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(rest);
			rest = NULL;
			return (free(buffer), NULL);
		}
		if (bytes == 0)
			break ;
		if (bytes >= 0 && bytes < BUFFER_SIZE + 1)
			buffer[bytes] = '\0';
		// printf("REST: %s \n", rest);
		rest = ft_strjoin_gnl(rest, buffer);
		// printf("REST: %s \n", rest);
	}
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = ft_readfile_gnl(fd, rest);
	if (!rest || !rest[0])
		return (free(rest), NULL);
	line = ft_complete_line(rest);
	rest = ft_clean_rest(rest);
	return (line);
}

// int	main()
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("only_nl.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
