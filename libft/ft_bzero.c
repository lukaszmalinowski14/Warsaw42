/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:36:40 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/11 20:26:56 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // for size_t
// #include <stdio.h>

void ft_bzero(void *s, size_t n)
{
	size_t i;
	unsigned char *ptr;

	ptr = (unsigned char *)s;
	i = 0;

	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

// int main(void)
// {
// 	size_t i = 0;
// 	char str[] = "Hello World!";
// 	printf("%s\n", str);
// 	ft_bzero(str, 5);

// 	while (i < sizeof(str))
// 	{
// 		if (str[i] == '\0')
// 			printf("Byte %zu: \\0\n", i);
// 		else
// 			printf("Byte %zu: %c\n", i, str[i]);
// 		i++;
// 	}
// 	return (0);
// }
