/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:16:02 by paapahid          #+#    #+#             */
/*   Updated: 2025/11/19 20:27:27 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_gnl(char *str)
{
	size_t	len;
	size_t	i;
	char	*dup;

	if (!str)
		return (NULL);
	len = ft_strlen_gnl(str);
	dup = malloc(len * sizeof(char) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr_gnl(char *str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	str_len;
	size_t	i;

	if (!str)
		return (NULL);
	str_len = ft_strlen_gnl(str);
	if (start >= str_len || len == 0)
	{
		// free(str);
		// str = NULL;
		return (ft_strdup_gnl(""));
	}
	if (len > str_len - start)
		len = str_len - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (str[start] && i < len)
	{
		sub[i] = str[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static void	*ft_memcpy_gnl(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	str = malloc(len1 + len2 + 1);
	if (!str)
		return (free(s1), NULL);
	if (s1)
		ft_memcpy_gnl(str, s1, len1);
	ft_memcpy_gnl(str + len1, s2, len2);
	free(s1);
	s1 = NULL;
	// printf("S1: %s", s1);
	str[len1 + len2] = '\0';
	return (str);
}

// char	*ft_strjoin_gnl(char *s1, const char *s2)
// {
// 	size_t	len1;
// 	size_t	len2;
// 	char	*str;

// 	len1 = ft_strlen_gnl(s1);
// 	len2 = ft_strlen_gnl(s2);
// 	str = malloc(len1 + len2 + 1);
// 	if (!str)
// 		return (NULL);
// 	if (s1)
// 	{
// 		ft_memcpy_gnl(str, s1, len1);
// 		free(s1);
// 	}
// 	ft_memcpy_gnl(str + len1, s2, len2);
// 	str[len1 + len2] = '\0';
// 	printf("S1: %s \n", s1);
// 	return (str);
// }
