/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:03:08 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/07 23:19:58 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <fcntl.h>

void ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

// int main(void)
// {
// 	int fd;
// 	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd == -1)
// 		return (1);

// 	ft_putstr_fd("Hello World!", fd);
// 	ft_putstr_fd("\n", fd);

// 	close(fd);
// 	return (0);
// }
