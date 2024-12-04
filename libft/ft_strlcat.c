/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:08:36 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/04 18:42:49 by lmalinow         ###   ########.fr       */
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
	size_t dst_len;
	size_t src_len;
	size_t i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = 0;
	while (i < dstsize - dst_len - 1 && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
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
