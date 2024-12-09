/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:49:07 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/09 20:03:27 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <fcntl.h>

void ft_putnbr_fd(int n, int fd)
{
	char c;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

// int main(void)
// {
// 	int c = -34543543;
// 	int fd;

// 	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd == -1)
// 	{
// 		write(2, "Error opening file\n", 19);
// 		return (1);
// 	}
// 	ft_putnbr_fd(42, fd);
// 	write(fd, "\n", 1);
// 	ft_putnbr_fd(-123456, fd);
// 	write(fd, "\n", 1);
// 	ft_putnbr_fd(-2147483648, fd);
// 	close(fd);
// 	return (0);
// }
