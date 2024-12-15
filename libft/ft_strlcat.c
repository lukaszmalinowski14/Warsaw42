/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:08:36 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/15 14:07:37 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // for size_t
// #include <stdio.h>

static size_t ft_strlen(const char *str)
{
	size_t i = 0;
	while (str[i])
		i++;
	return i;
}
size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t dest_length;
	size_t src_length;

	// Jeśli dstsize == 0, nie można dodać nic do dst, więc zwróć długość src
	if (dstsize == 0)
		return (src ? ft_strlen(src) : 0);
	if (!dst)
		*(volatile char *)0 = 0;

	// Jeśli src jest NULL, wywołaj segfault
	if (!src)
		*(volatile char *)0 = 0;

	// Jeśli dstsize == 0, zwróć długość src lub 0, jeśli src jest NULL

	src_length = ft_strlen(src);
	dest_length = ft_strlen(dst);
	j = dest_length;
	i = 0;
	if (dest_length < dstsize - 1 && dstsize > 0)
	{
		while (src[i] && dest_length + i < dstsize - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (dest_length >= dstsize)
		dest_length = dstsize;
	return (dest_length + src_length);
}

// int main(void)
// {
// 	char dest[10] = "Hello, ";
// 	const char *src = "World!";
// 	size_t total_len;

// 	total_len = ft_strlcat(dest, src, sizeof(dest));

// 	printf("Bufor docelowy: %s\n", dest);
// 	printf("Wymagana długość: %zu\n", total_len);
// 	printf("%s \n", dest);
// 	return (0);
// }
