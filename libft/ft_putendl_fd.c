/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:20:15 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/09 19:48:49 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <fcntl.h>

void ft_putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}
// int main(void)
// {
// 	int fd;

// 	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd == -1)
// 		return (1);
// 	ft_putendl_fd("Hello World!", fd);
// 	close(fd);
// 	return (0);
// }
