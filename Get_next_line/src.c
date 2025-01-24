/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:08:12 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/12 15:32:56 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#define BUFFER_SIZE 2

typedef struct s_buf
{
	char b[BUFFER_SIZE];
	ssize_t l;
} t_buf;

typedef struct s_str
{
	char *d;
	ssize_t l;
} t_str;

void gnl_memcpy(char *dest, char *src, ssize_t size)
{
	ssize_t i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

ssize_t find_newline(char *buffer, ssize_t chunk_len)
{
	ssize_t i;

	i = 0;
	while (i < chunk_len)
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

static void realloc_result(t_str *result, ssize_t new_l)
{
	char *old_result;

	if (new_l == result->l)
		return;
	old_result = result->d;
	result->d = (char *)malloc(sizeof(char) * new_l);
	if (old_result == NULL)
		return;
	if (result->d != NULL)
		gnl_memcpy(result->d, old_result, result->l);
	free(old_result);
}

static char add_to_result(t_str *result, t_buf *buf)
{
	ssize_t newline_pos;
	ssize_t append_l;

	if (buf->l <= 0)
		return (1);
	newline_pos = find_newline(buf->b, buf->l);
	append_l = buf->l;
	if (newline_pos != -1)
		append_l = newline_pos;
	realloc_result(result, result->l + append_l + 1);
	if (result->d != NULL)
	{
		gnl_memcpy(result->d + result->l, buf->b, append_l);
		result->d[result->l + append_l] = '\0';
		result->l += append_l;
		if (newline_pos != -1)
		{
			buf->l -= newline_pos;
			gnl_memcpy(buf->b, buf->b + newline_pos, buf->l);
			return (0);
		}
		return (1);
	}
	return (-1);
}

char *get_next_line(int fd)
{
	char loop;
	t_str result;
	static t_buf buf;

	result.d = NULL;
	result.l = 0;
	loop = 1;
	while (loop > 0)
	{
		loop = add_to_result(&result, &buf);
		if (loop > 0)
		{
			buf.l = read(fd, buf.b, sizeof(char) * BUFFER_SIZE);
			if (buf.l <= 0)
				loop = buf.l;
		}
	}
	if (loop == -1 && result.d != NULL)
	{
		free(result.d);
		result.d = NULL;
	}
	return (result.d);
}

int main()
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY); // Otwórz plik tylko do odczytu
	if (fd == -1)
	{
		// Obsługa błędu, jeśli plik nie zostanie otwarty
		perror("Error opening file");
		return 1;
	}
	// Odczytaj i wypisz każdą linię za pomocą get_next_line
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line); // Wypisanie linii
		free(line);			  // Zwolnienie pamięci dla każdej linii
	}
	close(fd); // Zamknij plik
	return 0;
}
