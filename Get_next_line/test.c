/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:50:14 by lmalinow          #+#    #+#             */
/*   Updated: 2025/01/12 15:50:48 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void ft_copy(char *src, char *dest, size_t n)
{
	size_t	i;

	i = 0;
	while(i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void ft_realloc_line(s_line *line, int n)
{
	char	*copy_line;
	size_t	i;

	i = 0;
	copy_line = line->str;
	line->str = malloc(sizeof(char) * (line->l + n + 1));
	if (copy_line == NULL)
		return;
	else
	{
		ft_copy(copy_line, line->str, line->l);
	}
}

int ft_new_line_pos(char* str)
{
	ssize_t n;

	n = 0;
	while(str[n])
	{
		if(str[n]=='\n')
			return (n+1);
		n++;
	}
	return (-1);
}

int ft_add_to_line(s_line *line, s_buf *buf)
{
	ssize_t new_line_mark;
	size_t append_size;

	if(buf->l<=0)
		return (1);
	new_line_mark = ft_new_line_pos(buf->str);
	append_size = buf->l;
	if (new_line_mark != -1)
		append_size = new_line_mark;
	ft_realloc_line(line, append_size);
	if(line->str != NULL)
	{
		ft_copy(buf->str, line->str + line->l, append_size);
		line->l += append_size;
		if (new_line_mark != -1)
		{
			buf->l = buf->l - append_size;
			ft_copy(buf->str + append_size, buf->str, buf->l);
			return (0);
		}
		return (1);
	}
	return (-1);
}

char *get_next_line(int fd)
{
	static s_buf	buf;
	s_line	line;
	size_t	loop;

	line.l = 0;
	line.str = NULL;
	loop = 1;
	while (loop > 0)
	{
		loop = ft_add_to_line(&line, &buf);
		if (loop > 0)
		{
			buf.l = read(fd, buf.str, sizeof(char) * BUFFER_SIZE);
			printf("|%s|\n", buf.str);
			if (buf.l <= 0)
				loop = buf.l;
		}
	}
	if (loop == -1 && line.str != NULL)
	{
		free(line.str);
		line.str = NULL;
	}
	return (line.str);
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
	while ((line= get_next_line(fd)) != NULL)
	{
		printf("returned line: %s\n", line);
		free(line);
	}
	close(fd); // Zamknij plik
	return 0;
}
