/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:20:35 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/07 13:31:14 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>
#include <stddef.h> // for size_t

static void *ft_memset(void *ptr, int value, size_t n)
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

void *ft_calloc(size_t nmemb, size_t size)
{
	void *ptr;
	size_t total_size;

	total_size = nmemb * size;
	if (nmemb != 0 && total_size / nmemb != size)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}

// int main(void)
// {
// 	int *arr;
// 	int n = 5;

// 	// Użycie ft_calloc do alokacji pamięci
// 	arr = (int *)ft_calloc(n, sizeof(int));

// 	if (!arr)
// 	{
// 		printf("Memory allocation failed!\n");
// 		return 1;
// 	}

// 	// Wyświetlanie wartości (wszystkie powinny być 0)
// 	for (int i = 0; i < n; i++)
// 	{
// 		printf("arr[%d] = %d\n", i, arr[i]);
// 	}
// 	free(arr);
// 	arr = (int *)calloc(n, sizeof(int));
// 	for (int i = 0; i < n; i++)
// 	{
// 		printf("arr[%d] = %d\n", i, arr[i]);
// 	}
// 	// Zwolnienie pamięci
// 	free(arr);

// 	return (0);
// }
