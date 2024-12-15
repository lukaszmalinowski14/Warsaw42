/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:32:03 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/15 14:14:39 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <fcntl.h>

void ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return;
	write(fd, &c, 1);
}

// int main(void)
// {
// 	int fd;
// 	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd == -1)
// 		return (1);

// 	ft_putchar_fd('A', fd);
// 	ft_putchar_fd('\n', fd);

// 	close(fd);
// 	return (0);
// }
