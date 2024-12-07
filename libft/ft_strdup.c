/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:42:11 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/07 13:31:22 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
#include <stdlib.h>
#include <stddef.h> // for size_t

static size_t ft_strlen(char *str)
{
	size_t len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
char *ft_strdup(const char *s)
{
	size_t i;
	char *copy;
	size_t len;

	i = 0;
	len = ft_strlen((char *)s);
	copy = (char *)malloc(len + 1);
	if (!copy)
		return (NULL);
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

// int main(void)
// {
// 	const char *original = "Hello, world!";
// 	char *copy;

// 	// Użycie ft_strdup do skopiowania ciągu znaków
// 	copy = ft_strdup(original);

// 	if (!copy)
// 	{
// 		printf("Memory allocation failed!\n");
// 		return 1;
// 	}

// 	// Wyświetlanie oryginału i kopii
// 	printf("Original: %s\n", original);
// 	printf("Copy: %s\n", copy);

// 	// Zwolnienie pamięci
// 	free(copy);

// 	// Wyświetlanie oryginału i kopii
// 	copy = strdup(original);
// 	printf("Original: %s\n", original);
// 	printf("Copy: %s\n", copy);
// 	free(copy);

// 	return (0);
// }
