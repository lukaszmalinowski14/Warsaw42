/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:20:43 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/09 20:13:01 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // for size_t
// #include <stdio.h>

static size_t ft_strlen(char *str)
{
	size_t i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t src_len;

	src_len = ft_strlen((char *)src);
	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

// int main(void)
// {
// 	char src[] = "Hello, World!";
// 	char dst[8]; // Mały bufor

// 	size_t copied = ft_strlcpy(dst, src, sizeof(dst));

// 	printf("Source: %s\n", src);
// 	printf("dest: %s\n", dst);
// 	printf("dst len: %zu\n", copied);

// 	return 0;
// }
