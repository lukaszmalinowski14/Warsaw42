/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:22:38 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/05 20:49:51 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // for size_t
// #include <stdio.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s1_ptr;
	unsigned char *s2_ptr;

	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	while (n--)
	{
		if (*s1_ptr != *s2_ptr)
			return ((int)(*s1_ptr - *s2_ptr));
		s1_ptr++;
		s2_ptr++;
	}
	return (0);
}

// int main(void)
// {
// 	char str1[] = "Hello World";
// 	char str2[] = "Hewwo World";
// 	printf("%d \n", ft_memcmp(str1, str2, 10));
// 	return (0);
// }
