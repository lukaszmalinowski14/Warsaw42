/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:35:18 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/05 20:22:17 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // for size_t
// #include <stdio.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *s_ptr;
	unsigned char byte;

	byte = (unsigned char)c;
	s_ptr = (unsigned char *)s;

	while (n--)
	{
		if (byte == *s_ptr)
			return ((void *)s_ptr);
		s_ptr++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char str[] = "Hello World";
// 	char *result;

// 	result = (char *)ft_memchr(str, 'W', 7);

// 	if (result != NULL)
// 	{
// 		printf("Found bite: %c on position : %ld\n", *result, result - str);
// 	}
// 	else
// 	{
// 		printf("bite not found.\n");
// 	}
// 	return (0);
// }
