/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:00:12 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/12 20:04:45 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // for size_t
// #include <stdio.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *dest_ptr;
	const unsigned char *src_ptr;
	size_t i;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest_ptr);
}

// int main(void)
// {
// 	char *src = "Hello World!";
// 	char dest[20];
// 	size_t n = 5;
// 	printf("%s\n,", (char *)ft_memcpy(dest, src, n));

// 	return (0);
// }
