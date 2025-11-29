/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:18:36 by paapahid          #+#    #+#             */
/*   Updated: 2025/11/19 20:28:03 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_substr_gnl(char *str, unsigned int start, size_t len);
size_t		ft_strlen_gnl(const char *str);
char	*ft_strjoin_gnl(char *s1, const char *s2);
char	*ft_strdup_gnl(char *str);

#endif
