/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:17:49 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/12 20:13:29 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // for size_t
// #include <stdio.h>

void *ft_memset(void *ptr, int value, size_t n)
{
	unsigned char *byte_ptr;
	unsigned char byte_value;
	size_t i;

	byte_ptr = (unsigned char *)ptr;
	byte_value = (unsigned char)value;
	i = 0;

	while (i < n)
	{
		byte_ptr[i] = byte_value;
		i++;
	}

	return (ptr);
}

// int main(void)
// {
// 	char str[] = "Hello World!";
// 	printf("%s\n", str);
// 	ft_memset(str, '4', 5);
// 	printf("%s\n", str);

// 	return (0);
// }
