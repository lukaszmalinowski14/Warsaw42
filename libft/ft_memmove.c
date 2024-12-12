/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:15:27 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/12 20:09:08 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // for size_t
// #include <stdio.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *dest_ptr = (unsigned char *)dest;
	const unsigned char *src_ptr = (const unsigned char *)src;
	size_t i;

	if (dest_ptr == src_ptr)
		return (dest);
	if (dest_ptr > src_ptr)
	{
		i = n;
		while (i > 0)
		{
			dest_ptr[i - 1] = src_ptr[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dest_ptr[i] = src_ptr[i];
			i++;
		}
	}
	return dest;
}

// int main(void)
// {
// 	char *str = "Hello World!";
// 	char dest[20];
// 	size_t n = 7;
// 	ft_memmove(dest, str, n);
// 	printf("%s\n", dest);
// 	return (0);
// }
