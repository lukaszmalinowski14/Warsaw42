#include <stdio.h>
#include <string.h>

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
// void *ft_memmove(void *dest, const void *src, size_t n)
// {
// 	unsigned char *dest_ptr = (unsigned char *)dest;
// 	const unsigned char *src_ptr = (const unsigned char *)src;
// 	size_t i;

// 	if (dest_ptr == src_ptr)
// 		return (dest);
// 	if (dest_ptr > src_ptr && dest_ptr < src_ptr + n)
// 	{
// 		i = n;
// 		while (i > 0)
// 		{
// 			dest_ptr[i - 1] = src_ptr[i - 1];
// 			i--;
// 		}
// 	}
// 	else
// 	{
// 		i = 0;
// 		while (i < n)
// 		{
// 			dest_ptr[i] = src_ptr[i];
// 			i++;
// 		}
// 	}
// 	return dest;
// }
#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	char *s;
	char *d;
	size_t i;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (d > s)
		while (len-- > 0)
			d[len] = s[len];
	else
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	return (dst);
}
int main()
{
	// char str[] = "Hello, World!";
	// char dest[10];
	// memcpy(dest, str, 10);
	// // Ręcznie dodajemy znak null, aby zakończyć ciąg
	// dest[10] = '\0';
	// printf("Result: %s\n", dest);
	// return 0;

	char str[] = "Hello, World!aaaaaaaaaaaaaaaaa";
	char dest[20];

	// Przemieszczanie danych w obrębie tego samego ciągu (nakładające się obszary)
	ft_memmove(str + 15, str, 20);
	// ft_memcpy(str + 15, str, 20);

	printf("Result after memmove: %s\n", str);
	return (0);
}