/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:52:47 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/07 13:31:56 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // for size_t
// #include <stdio.h>

static int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && *s2 && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
static size_t ft_strlen(const char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t little_len = ft_strlen(little);
	size_t i;

	if (little_len == 0)
		return ((char *)big);
	i = 0;
	while (i + little_len <= len)
	{
		if (ft_strncmp(big + i, little, little_len) == 0)
			return (char *)(big + i);
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	const char *haystack = "Hello, world!";
// 	const char *needle = "world";
// 	size_t len = 15;

// 	char *result = ft_strnstr(haystack, needle, len);

// 	if (result)
// 	{
// 		printf("Found: %s\n", result);
// 	}
// 	else
// 	{
// 		printf("Not found.\n");
// 	}
// 	return (0);
// }
