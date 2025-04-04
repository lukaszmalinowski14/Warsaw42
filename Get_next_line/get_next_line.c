/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:18:56 by lmalinow          #+#    #+#             */
/*   Updated: 2025/03/09 16:43:43 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
	size_t len = 0;
	while (s[len])
		len++;
	return len;
}

char *ft_strjoin(char *s1, char *s2)
{
	size_t len1 = ft_strlen(s1);
	size_t len2 = ft_strlen(s2);
	char *new_str = malloc(len1 + len2 + 1);
	if (!new_str)
		return NULL;

	size_t i = 0;
	for (; i < len1; i++)
		new_str[i] = s1[i];

	for (size_t j = 0; j < len2; j++, i++)
		new_str[i] = s2[j];

	new_str[i] = '\0';
	return new_str;
}

char *ft_strdup(const char *s)
{
	size_t len = ft_strlen(s);
	char *dup = malloc(len + 1);
	if (!dup)
		return NULL;

	for (size_t i = 0; i < len; i++)
		dup[i] = s[i];

	dup[len] = '\0';
	return dup;
}

char *ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (char *)s;
		s++;
	}
	if (c == '\0')
		return (char *)s;
	return NULL;
}
static char *read_line(int fd, char *buffer, char *remainder)
{
	int bytes_read;
	char *temp;
	char *newline;

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(remainder, buffer);
		free(remainder);
		remainder = temp;

		if ((newline = ft_strchr(remainder, '\n')))
		{
			*newline = '\0';
			return ft_strdup(remainder);
		}
	}
	return NULL;
}
char *get_next_line(int fd)
{
	static char *remain;
	char buffer[BUFFER_SIZE];
	char *line;

	if (fd < 0 || BUFFER_SIZE <=0)
		return NULL;
	line = read_line(fd, buffer, remain);
	if (line)
	{
		remain = ft_strdup(remain + ft_strlen(line));
		return line;
	}

	return NULL;
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)) !=NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
