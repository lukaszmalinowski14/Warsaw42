/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:19:09 by lmalinow          #+#    #+#             */
/*   Updated: 2025/01/11 11:10:54 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 2

typedef struct buf{
	char str[BUFFER_SIZE];
	ssize_t l;
} s_buf;

typedef struct line{
	char *str;
	ssize_t l;
} s_line;

char *get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);

#endif
