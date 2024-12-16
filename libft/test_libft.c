/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:19:36 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/16 19:06:49 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// test ft_isalpha
// int main()
// {
// 	char a = 'a';
// 	char b = '1';
// 	printf("%d\n", ft_isalpha(a));
// 	printf("%d\n", ft_isalpha(b));
// 	return (0);
// }

// test ft_isdigit
// int main()
// {
// 	char a = 'a';
// 	char b = '1';
// 	char c = '-';
// 	char d = '\\';
// 	char e = 75;
// 	printf("%c - %d\n", a, ft_isdigit(a));
// 	printf("%c - %d\n", b, ft_isdigit(b));
// 	printf("%c - %d\n", c, ft_isdigit(c));
// 	printf("%c - %d\n", d, ft_isdigit(d));
// 	printf("%c - %d\n", e, ft_isdigit(e));
// 	return (0);
// }

// test ft_isalnum
// int main()
// {
// 	char a = 'a';
// 	char b = '1';
// 	char c = '-';
// 	char d = '\\';
// 	char e = 75;
// 	char f = 128;
// 	printf("%c - %d\n", a, ft_isalnum(a));
// 	printf("%c - %d\n", b, ft_isalnum(b));
// 	printf("%c - %d\n", c, ft_isalnum(c));
// 	printf("%c - %d\n", d, ft_isalnum(d));
// 	printf("%c - %d\n", e, ft_isalnum(e));
// 	printf("%c - %d\n", f, ft_isalnum(f));
// 	return (0);
// }

// test ft_isascii
// int main()
// {
// 	char a = 'a';
// 	char b = '1';
// 	char c = '-';
// 	char d = '\\';
// 	char e = 75;
// 	char f = 128;
// 	printf("%c - %d\n", a, ft_isascii(a));
// 	printf("%c - %d\n", b, ft_isascii(b));
// 	printf("%c - %d\n", c, ft_isascii(c));
// 	printf("%c - %d\n", d, ft_isascii(d));
// 	printf("%c - %d\n", e, ft_isascii(e));
// 	printf("%c - %d\n", f, ft_isascii(f));
// 	return (0);
// }

// test ft_isprint
// int main()
// {
// 	char chars[] = {'a', '1', '-', '\\', 75, 128, 7, 31, 32, 33};
// 	int i = 0;

// 	while (chars[i])
// 	{
// 		printf("%c - %d\n", chars[i], ft_isprint(chars[i]));
// 		i++;
// 	}
// 	return (0);
// }

// test ft_strlen
// int main()
// {
// 	char *chars[] = {"sfsdf", "Hello World!", NULL};
// 	int i = 0;

// 	while (chars[i])
// 	{
// 		printf("%s - %zu\n", chars[i], ft_strlen(chars[i]));
// 		i++;
// 	}
// 	return (0);
// }

// test ft_memset
// int main()
// {
// 	char str1[] = "Hello World!";
// 	char str2[] = "Hello World!";

// 	printf("before memset: %s\n", str1);
// 	printf("%s\n", (char *)ft_memset(str1, 'X', 5));

// 	printf("before memset: %s\n", str2);
// 	printf("%s\n", (char *)memset(str2, 'X', 5));

// 	return (0);
// }
// ###################################################################################
// test ft_bzero
// int main()
// {
// 	char str1[] = "Hello World!";
// 	char str2[] = "Hello World!";

// 	printf("before ft_bzero: %s\n", str1);
// 	ft_bzero(str1, 5);
// 	printf("after ft_bzero: %s\n", str1);
// 	for (int i = 0; i < (int)sizeof(str1); i++)
// 	{
// 		if (str1[i] == '\0')
// 		{
// 			printf("\\0 ");
// 		}
// 		else
// 		{
// 			printf("%c ", str1[i]);
// 		}
// 	}
// 	printf("\n");

// 	printf("before bzero: %s\n", str2);
// 	bzero(str2, 5);
// 	printf("after bzero: %s\n", str2);
// 	for (int i = 0; i < (int)sizeof(str1); i++)
// 	{
// 		if (str1[i] == '\0')
// 		{
// 			printf("\\0 ");
// 		}
// 		else
// 		{
// 			printf("%c ", str1[i]);
// 		}
// 	}
// 	printf("\n");
// 	return (0);
// }

// ##################################################################3
// The memcpy() function copies n bytes from memory area src to
// memory area dest.The memory areas must not overlap.
// test ft_memcpy
// int main(void)
// {
// 	char src[20] = "Hello World!";
// 	char dest[20];
// 	size_t n = 5;
// 	// normal
// 	ft_memcpy(dest, src, n);
// 	printf("normal: %s \n", dest);
// 	// dest or src null segmentation fault
// 	ft_memcpy(src + 6, src, 5);
// 	printf("overlap: %s\n", src);
// 	// n=0
// 	char src2[20] = "Hello World!";
// 	char dest2[20];
// 	ft_memcpy(dest2, src2, 0);
// 	printf("n=0: %s\n", dest2);
// 	return (0);
// }

// ##################################################################
// The ft_memmove() function copies n bytes from memory area src to memory area dest. The memory areas may overlap
// test ft_memmove
// void test_memmove()
// {
//     char src1[50] = "Hello, World! This is a test for ft_memmove.";
//     char dest1[50];
//     char dest2[50];
// 	memset(dest1,'0',sizeof(dest1));
// 	memset(dest2,'0',sizeof(dest1));

//     // Test 1: Normal copy
//     printf("Test 1: Normal copy\n");
//     ft_memmove(dest1, src1, 13);
//     memmove(dest2, src1, 13);
//     printf("ft_memmove: %s\n", dest1);
//     printf("memmove   : %s\n", dest2);
//     printf("Comparison: %s\n\n", strcmp(dest1, dest2) == 0 ? "OK" : "FAILED");

//     // Test 2: Overlapping regions (dest > src)
//     printf("Test 2: Overlapping regions (dest > src)\n");
//     char overlap1[50] = "Hello, Overlapping memory regions!";
//     char overlap2[50] = "Hello, Overlapping memory regions!";
//     ft_memmove(overlap1 + 7, overlap1, 10);
//     memmove(overlap2 + 7, overlap2, 10);
//     printf("ft_memmove: %s\n", overlap1);
//     printf("memmove   : %s\n", overlap2);
//     printf("Comparison: %s\n\n", strcmp(overlap1, overlap2) == 0 ? "OK" : "FAILED");

//     // Test 3: Overlapping regions (src > dest)
//     printf("Test 3: Overlapping regions (src > dest)\n");
//     char overlap3[50] = "Hello, Overlapping memory regions!";
//     char overlap4[50] = "Hello, Overlapping memory regions!";
//     ft_memmove(overlap3, overlap3 + 7, 10);
//     memmove(overlap4, overlap4 + 7, 10);
//     printf("ft_memmove: %s\n", overlap3);
//     printf("memmove   : %s\n", overlap4);
//     printf("Comparison: %s\n\n", strcmp(overlap3, overlap4) == 0 ? "OK" : "FAILED");

//     // Test 4: N = 0 (no bytes should be copied)
//     printf("Test 4: N = 0\n");
//     char empty1[50] = "Nothing changes here.";
//     char empty2[50] = "Nothing changes here.";
//     ft_memmove(empty1, empty1 + 5, 0);
//     memmove(empty2, empty2 + 5, 0);
//     printf("ft_memmove: %s\n", empty1);
//     printf("memmove   : %s\n", empty2);
//     printf("Comparison: %s\n\n", strcmp(empty1, empty2) == 0 ? "OK" : "FAILED");

//     // // Test 5: NULL as argument
//     // printf("Test 5: NULL as argument\n");
//     // char *null_result1 = ft_memmove(NULL, src1, 5);
//     // char *null_result2 = memmove(NULL, src1, 5); // Warning: May cause a crash in built-in memmove.
//     // printf("ft_memmove: %s\n", null_result1 == NULL ? "NULL" : "Not NULL");
//     // printf("memmove   : %s\n", null_result2 == NULL ? "NULL" : "Not NULL");
//     // printf("Comparison: %s\n\n", null_result1 == null_result2 ? "OK" : "FAILED");
// }

// int main()
// {
//     test_memmove();
//     return 0;
// }

// ##################################################################
// The strlcpy() function copies up to size - 1 characters from the NUL-terminated string src to dst, NUL-terminating the result.
// test ft_strlcpy
// int main(void)
// {
// 	char src[40] = "He"; //"Hello World! This is a test message.";
// 	char dst[20];
// 	memset(dst, 'X', sizeof(dst));
// 	size_t n = 6;
// 	printf("Before ft_memmove: %s\n", dst);
// 	ft_strlcpy(dst, src, n);
// 	for (int i = 0; i < 8; i++)
// 	{
// 		if (dst[i] == '\0')
// 		{
// 			printf("\\0 ");
// 		}
// 		else
// 		{
// 			printf("%c ", dst[i]);
// 		}
// 	}
// 	printf("\n");
// 	// printf("After ft_memmove: %s\n", dst);
// 	return (0);
// }

// ##################################################################
// The strlcat() function copies up to size - 1 characters from the NUL-terminated string src to dst, NUL-terminating the result.
// test ft_strlcat
// int main(void)
// {
// 	char src[14] = "Hello World!";
// 	char dst[22] = "XXX";

// 	char src2[14] = "Hello World!";
// 	char dst2[10] = "Elo ";
// 	// memset(dst, 'X', sizeof(dst));
// 	// size_t n = 5;
// 	printf("number of bits: %d :new dst: %s\n", (int)ft_strlcat(dst, src, sizeof(dst)), dst);
// 	printf("number of bits: %d :new dst: %s\n", (int)ft_strlcat(dst2, src2, sizeof(dst2)), dst2);
// 	for (int i = 0; i < (int)sizeof(dst); i++)
// 	{
// 		if (dst[i] == '\0')
// 		{
// 			printf("\\0 ");
// 		}
// 		else
// 		{
// 			printf("%c ", dst[i]);
// 		}
// 	}
// 	printf("\n");
// 	for (int i = 0; i < (int)sizeof(dst2); i++)
// 	{
// 		if (dst2[i] == '\0')
// 		{
// 			printf("\\0 ");
// 		}
// 		else
// 		{
// 			printf("%c ", dst2[i]);
// 		}
// 	}
// 	printf("\n");
// 	return (0);
// }

// #####################################################
// toupper convert letter to upper
//  test toupper
// int main(void)
// {
// 	char test[] = "Hello-World";
// 	size_t n = 0;
// 	while (n < sizeof(test))
// 	{
// 		test[n] = ft_toupper(test[n]);
// 		n++;
// 	}
// 	printf("%s\n", test);
// 	return (0);
// }

// #####################################################
// tolower convert letter to lower
//  test tolower
// int main(void)
// {
// 	char test[] = "Hello WORLD!";
// 	size_t n = 0;
// 	while (n < sizeof(test))
// 	{
// 		test[n] = ft_tolower(test[n]);
// 		n++;
// 	}
// 	printf("%s\n", test);
// 	return (0);
// }

// #####################################################
// strchr The strchr() function returns a pointer to the first occurrence of the character c in the string s.
// or NULL if the character is not found.
//  test strchr
// int main(void)
// {
// 	char src[] = "Hello WORLD!";
// 	char *dst;
// 	char b = 'Z';
// 	dst = ft_strchr(src, b);
// 	if (dst == NULL)
// 	{
// 		printf("%c not found.\n", b);
// 	}
// 	else
// 	{
// 		printf("found %c : %s\n", b, dst);
// 	}

// 	return (0);
// }

// ######################################################
// The strrchr() function returns a pointer to the last occurrence of the character c in the string s.
// or null if not found
// test strrchr
// int main(void)
// {
// 	char src[] = "DHello WORLD!";
// 	char *dst;
// 	char b = 'D';
// 	dst = ft_strrchr(src, b);
// 	if (dst == NULL)
// 	{
// 		printf("%c not found.\n", b);
// 	}
// 	else
// 	{
// 		printf("found %c : %s\n", b, dst);
// 	}

// 	return (0);
// }

// ##################################
// function compares the two strings s1 and s2. It returns an integer less than, equal to, or greater than zero if s1 is found
// only compares the first (at most) n bytes of s1 and s2.
// test strncmp
// int main(void)
// {
// 	char *s1 = "HelLlo";
// 	char *s2 = "Hello";
// 	int eval;
// 	int n = 2;

// 	eval = ft_strncmp(s1, s2, n);
// 	printf("%d\n", eval);

// 	return (0);
// }

// #########################################
// The memchr() function scans the initial n bytes of the memory area pointed to by s for the first instance of c.
// or NULL if the character does not occur in the given memory area.
// test memchr
// int main(void)
// {
// 	char *s = "Hello World!";
// 	char c = 'W';
// 	char *d;
// 	size_t n = 4;

// 	d = ft_memchr(s, c, n);
// 	if (d != NULL)
// 		printf("%s\n", d);
// 	else
// 		printf("%c Not found \n", c);
// 	return (0);
// }

// #######################################
// The memcmp() function compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2.
// return value, the sign is determined by the sign of the difference between the first pair of bytes
// test memcmp
// int main(void)
// {
// 	char *s1 = "HelLlo";
// 	char *s2 = "Hello";
// 	int eval;
// 	sizet_t n = 4;

// 	eval = ft_memcmp(s1, s2, n);
// 	printf("%d\n", eval);

// 	return (0);
// }

// #####################################################
// The strnstr() function locates the first	occurrence of the  null-termi-
// nated string little in the string big, where not more than len charac -
// 										   ters are searched.
// tesst strnstr
// int main(void)
// {
// 	char *s1 = "Hello World!";
// 	char *s2 = "Wor";
// 	char *eval;
// 	size_t n = 10;

// 	eval = ft_strnstr(s1, s2, n);
// 	if (eval != NULL)
// 		printf("%s\n", eval);
// 	else
// 		printf("Not found! \n");

// 	return (0);
// }
// ###############################################
// The atoi() function converts the initial portion of the string pointed to by nptr to int. The behavior is the
// test atoi
// int main(void)
// {
// 	char *test_cases[] = {
// 		"123", "-456", "0", "2147483647", "-2147483648",
// 		"   42", "\t\n  -123", "123abc", "42!@#$",
// 		"", "abc", "   ", "   -+42", "++42",
// 		"2147483648", "-2147483649", " \v\t42"};
// 	int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
// 	for (int i = 0; i < num_cases; i++)
// 	{
// 		printf("Input: '%s'\n", test_cases[i]);
// 		printf("atoi: %d\n", atoi(test_cases[i]));
// 		printf("ft_atoi: %d\n", ft_atoi(test_cases[i]));
// 		printf("-----------------------------\n");
// 	}
// 	return (0);
// }
// ########################################################3
// calloc  function allocates size bytes and returns a pointer to the allocated memory.
// The memory is set to zero. If nmemb or size is 0, then calloc() returns either NULL,
// or a unique pointer value that can later be successfully passed to free().
// test calloc
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

// 	int *zero_alloc = (int *)calloc(0, sizeof(int));
// 	if (zero_alloc == NULL)
// 	{
// 		printf("calloc return  NULL allocated 0 elements.\n");
// 	}
// 	else
// 	{
// 		printf("calloc not returned NULL, but pointer: %p (is not alocated).\n", (void *)zero_alloc);
// 		free(zero_alloc);
// 	}
// 	return (0);
// }
// ############################################################
// The strdup() function returns a pointer to a new string which is a duplicate of the string s.
// Memory for the new string is obtained with malloc(3), and can be freed with free(3).
// test strdup
// int main(void)
// {
// 	// copy regular str
// 	char *src = "Hello, World!";
// 	char *copy = ft_strdup(src);
// 	if (copy == NULL)
// 	{
// 		printf("error memory alocation!\n");
// 		return 1;
// 	}

// 	printf("original: %s\n", src);
// 	printf("copy: %s\n", copy);
// 	free(copy);

// 	// Test 2: Kopiowanie pustego ciągu
// 	char *empty = "";
// 	char *empty_copy = ft_strdup(empty);
// 	if (empty_copy == NULL)
// 	{
// 		printf("Błąd alokacji pamięci!\n");
// 		return 1;
// 	}

// 	printf("empty str ori: '%s'\n", empty);
// 	printf("empty str copy: '%s'\n", empty_copy);
// 	free(empty_copy);
// 	return (0);
// }
// #############################################################
// ft_substr Allocates (with malloc(3)) and returns a substring
// from the string ’s’.The substring begins at index ’start’ and is of
// 	maximum size ’len’.
int main(void)
{
	// Test 1: Podciąg zaczynający się od początku ciągu
	char *s1 = "Hello World!";
	char *sub1 = ft_substr(s1, 0, 5);
	printf("Test 1: '%s'\n", sub1); // expected: "Hello"
	free(sub1);

	// Test 2: Podciąg zaczynający się od środka ciągu
	char *sub2 = ft_substr(s1, 6, 5);
	printf("Test 2: '%s'\n", sub2); // Oczekiwany wynik: "World"
	free(sub2);

	// Test 3: Podciąg, gdzie start jest większy niż długość ciągu
	char *sub3 = ft_substr(s1, 15, 5);
	printf("Test 3: '%s'\n", sub3); // Oczekiwany wynik: ""
	free(sub3);

	// Test 4: Podciąg, gdzie długość jest większa niż dostępna długość w ciągu
	char *sub4 = ft_substr(s1, 6, 20);
	printf("Test 4: '%s'\n", sub4); // Oczekiwany wynik: "World!"
	free(sub4);

	char *sub5=ft_substr("HOLA MUNDO", 8, 5);
	printf("Test 4: '%s'\n", sub5); // Oczekiwany wynik: "World!"

	return 0;
}
// ##############################################################
// ft_strjoin
// Allocates (with malloc(3)) and returns a new
// string, which is the result of the concatenation
// 			of ’s1’ and ’s2’.
// int main(void)
// {
// 	char *s1 = "Hello ";
// 	char *s2 = "World!";
// 	char *sub1 = ft_strjoin(s1, s2);
// 	printf("test 1: %s\n", sub1);
// 	free(sub1);

// 	char *s5 = "";
// 	char *s6 = "";
// 	char *result3 = ft_strjoin(s5, s6);
// 	printf("Test 2: '%s'\n", result3); // expected: ""
// 	free(result3);
// 	return (0);
// }
// ############################################
// ft_strtrim
// Allocates(with malloc(3)) and returns a copy of
// ’s1’ with the characters specified in ’set’ removed
// 							  from the beginning and the end of the string.
// int main(void)
// {
// 	// Test 1: remove from start and end
// 	char *s1 = "  ***Hello World!***  ";
// 	char *set = " *";
// 	char *result = ft_strtrim(s1, set);
// 	printf("Test 1: '%s'\n", result); // expected: "Hello World!"
// 	free(result);

// 	// Test 2: no char to remove
// 	char *s2 = "Hello World!";
// 	char *set2 = "xyz";
// 	char *result2 = ft_strtrim(s2, set2);
// 	printf("Test 2: '%s'\n", result2); // expected: "Hello World!"
// 	free(result2);

// 	// Test 3: one side
// 	char *s3 = "###Hello World!";
// 	char *set3 = "#";
// 	char *result3 = ft_strtrim(s3, set3);
// 	printf("Test 3: '%s'\n", result3); // expected: "Hello World!"
// 	free(result3);

// 	// Test 4: from empty string
// 	char *s4 = "";
// 	char *set4 = "abc";
// 	char *result4 = ft_strtrim(s4, set4);
// 	printf("Test 4: '%s'\n", result4); // expected: ""
// 	free(result4);

// 	return (0);
// }
// ##################################################
// ft_split
// Allocates (with malloc(3)) and returns an array
// of strings obtained by splitting ’s’ using the
// 	character ’c’ as a delimiter.The array must end
// 		with a NULL pointer.
// int main(void)
// {
// 	// Test 1: many delimeters
// 	char *s1 = "Hello,World,This,Is,A,Test";
// 	char delimiter1 = ',';
// 	char **result1 = ft_split(s1, delimiter1);

// 	printf("Test 1:\n");
// 	for (int i = 0; result1[i] != NULL; i++)
// 	{
// 		printf("'%s'\n", result1[i]); // expected: "Hello", "World", "This", "Is", "A", "Test"
// 	}
// 	for (int i = 0; result1[i] != NULL; i++)
// 	{
// 		free(result1[i]);
// 	}
// 	free(result1);

// 	// Test 2: no delimeter in s2
// 	char *s2 = "HelloWorld";
// 	char delimiter2 = ',';
// 	char **result2 = ft_split(s2, delimiter2);

// 	printf("\nTest 2:\n");
// 	for (int i = 0; result2[i] != NULL; i++)
// 	{
// 		printf("'%s'\n", result2[i]); // expected: "HelloWorld"
// 	}
// 	for (int i = 0; result2[i] != NULL; i++)
// 	{
// 		free(result2[i]);
// 	}
// 	free(result2);

// 	// Test 3: empty string
// 	char *s3 = "";
// 	char delimiter3 = ',';
// 	char **result3 = ft_split(s3, delimiter3);

// 	printf("\nTest 3:\n");
// 	if (result3 == NULL || result3[0] == NULL)
// 	{
// 		printf("empty string: no result.\n");
// 	}
// 	free(result3);

// 	return (0);
// }

// #########################################################
// ft_itoa //Allocates (with malloc(3)) and returns a string
// representing the integer received as an argument.Negative numbers must be handled.

// int main(void)
// {
// 	// Test 1: positive number
// 	int n1 = 12345;
// 	char *result1 = ft_itoa(n1);
// 	printf("Test 1: %s (Expected:: 12345)\n", result1);
// 	free(result1);

// 	// Test 2: negative number
// 	int n2 = -12345;
// 	char *result2 = ft_itoa(n2);
// 	printf("Test 2: %s (Expected:: -12345)\n", result2);
// 	free(result2);

// 	// Test 3: 0
// 	int n3 = 0;
// 	char *result3 = ft_itoa(n3);
// 	printf("Test 3: %s (Expected:: 0)\n", result3);
// 	free(result3);

// 	// Test 4: min int
// 	int n4 = -2147483648;
// 	char *result4 = ft_itoa(n4);
// 	printf("Test 4: %s (Expected:: -2147483648)\n", result4);
// 	free(result4);

// 	// Test 5: max int
// 	int n5 = 2147483647;
// 	char *result5 = ft_itoa(n5);
// 	printf("Test 5: %s (Expected:: 2147483647)\n", result5);
// 	free(result5);

// 	// Test 6: 00 at the begining
// 	int n6 = 1234;
// 	char *result6 = ft_itoa(n6);
// 	printf("Test 6: %s (Expected:: 1234)\n", result6);
// 	free(result6);
// }
// ######################################################
//  ft_strmapi
// Applies the function f to each character of the
// 	string s,
// 	passing its index as the first argument
// 		and the character itself as the second.A new string is created(using malloc(3)) to collect the
// 	results from the successive applications of f.
// char test_function(unsigned int index, char c)
// {
// 	// Na przykład: zmienia każdą literę na jej indeks + litera
// 	return (c + index);
// }
// int main(void)
// {
// 	// Testy
// 	// Test 1: Zwykły ciąg znaków
// 	char *s1 = "abcd";
// 	char *result1 = ft_strmapi(s1, test_function);
// 	printf("Test 1: %s (expected: 'aceg')\n", result1);
// 	free(result1);

// 	// Test 3: Ciąg pusty
// 	char *s3 = "";
// 	char *result3 = ft_strmapi(s3, test_function);
// 	printf("Test 3: %s (expected: '')\n", result3);
// 	free(result3);

// 	// Test 6: Ciąg z dużymi literami
// 	char *s6 = "ABCDEF";
// 	char *result6 = ft_strmapi(s6, test_function);
// 	printf("Test 6: %s (expected: 'ACEGIK')\n", result6);
// 	free(result6);

// 	// Test 7: Ciąg z liczbami
// 	char *s7 = "1234";
// 	char *result7 = ft_strmapi(s7, test_function);
// 	printf("Test 7: %s (expected: '1357')\n", result7);
// 	free(result7);

// 	return (0);
// }
// ####################################################
// ft_striteri
// Applies the function ’f’ on each character of
// the string passed as argument, passing its index
// 								   as first argument.Each character is passed by
// 									   address to ’f’ to be modified if necessary.
// void test_function(unsigned int index, char *c)
// {
// 	*c = *c + index;
// }
// int main(void)
// {
// 	// regular string
// 	char s[] = "abcd";
// 	ft_striteri(s, test_function);
// 	printf("Test 1: '%s' (expected: 'aceg')\n", s);

// 	// empty string
// 	char s1[] = "";
// 	ft_striteri(s1, test_function);
// 	printf("Test 3: '%s' (expected: '')\n", s1);
// 	return (0);
// }
// #########################################
// ft_putchar_fd
// Outputs the character ’c’ to the given file descriptor.
// int main(void)
// {
// 	char c = 'E';

// 	// Test 1: Zapisz znak wielokrotnie do stdout
// 	printf("Test 5: expected: 'EEEE'\n");
// 	for (int i = 0; i < 4; i++)
// 	{
// 		ft_putchar_fd(c, 1); // Zapis do stdout
// 	}
// 	printf("\n");
// 	char c2 = 'A';

// 	// Test 2: stderr
// 	printf("stderr expected: 'A'\n");
// 	ft_putchar_fd(c2, 2);
// 	printf("\n");

// 	// test3 to file
// 	int fd;
// 	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	printf("saved to file output.txt");
// 	for (int i = 0; i < 4; i++)
// 	{
// 		ft_putchar_fd(c, fd);
// 	}
// 	printf("\n");
// 	return (0);
// }
// ###############################################
// ft_putstr_fd
// Outputs the string ’s’ to the given file descriptor.
// int main(void)
// {
// 	char *s = "Hello, world!";

// 	// Test 1: to stdout
// 	printf("Test 1: expected: 'Hello, world!'\n");
// 	ft_putstr_fd(s, 1);
// 	printf("\n");
// 	// Test 2: empty to stdout
// 	char *s2 = "";
// 	printf("Test 2: expected: \n");
// 	ft_putstr_fd(s2, 1);
// 	printf("\n");
// 	// test3: write to file
// 	char *s3 = "Text written to file";
// 	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd == -1)
// 	{
// 		perror("Failed to open file");
// 		exit(1);
// 	}

// 	// Test 3: Zapisz ciąg do pliku
// 	ft_putstr_fd(s3, fd);

// 	// Zamknij plik
// 	close(fd);
// 	printf("Test 3: expected text in file: 'Text written to file'\n");
// 	return (0);
// }
// ######################################################
// ft_putendl_fd
// Outputs the string ’s’ to the given file descriptor followed by a newline.
// int main(void)
// {
// 	char *s = "Hello, world!";

// 	// Test 1: Zapisz ciąg do standardowego wyjścia (stdout) z nową linią
// 	printf("Test 1: expected: 'Hello, world!\\n'\n");
// 	ft_putendl_fd(s, 1);
// 	printf("\n");
// 	// test 2: to file
// 	char *s2 = "Text written to file";
// 	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd == -1)
// 	{
// 		perror("Failed to open file");
// 		exit(1);
// 	}
// 	ft_putendl_fd(s2, fd);
// 	close(fd);
// 	printf("Test 2: file 'output.txt'. expected: 'Text written to file\\n'\n");
// 	return (0);
// }
// ######################################################
// ft_putnbr_fd
// Outputs the integer ’n’ to the given file descriptor.
// void test_ft_putnbr_fd_basic(void)
// {
// 	printf("Test 1: 123 to statndard output (stdout)\n");
// 	ft_putnbr_fd(123, 1);
// 	printf("\n");
// }
// void test_ft_putnbr_fd_file(void)
// {
// 	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd == -1)
// 	{
// 		perror("Failed to open file");
// 		exit(1);
// 	}

// 	printf("Test 3: number: 789 to file: 'output.txt'\n");
// 	ft_putnbr_fd(789, fd);
// 	close(fd);
// }
// void test_ft_putnbr_fd_min_int(void)
// {
// 	printf("Test 6: INT_MIN (-2147483648) to (stdout)\n");
// 	ft_putnbr_fd(-2147483648, 1); // Zapisz najmniejszą liczbę całkowitą
// 	printf("\n");
// }

// void test_ft_putnbr_fd_max_int(void)
// {
// 	printf("Test 7: INT_MAX (2147483647) to (stdout)\n");
// 	ft_putnbr_fd(2147483647, 1); // Zapisz największą liczbę całkowitą
// 	printf("\n");
// }
// int main(void)
// {
// 	test_ft_putnbr_fd_basic();
// 	test_ft_putnbr_fd_file();
// 	test_ft_putnbr_fd_min_int();
// 	test_ft_putnbr_fd_max_int();
// 	return (0);
// }
// #####################################################
// ft_lstnew
// Allocates (with malloc(3)) and returns a new node.
// The member variable ’content’ is initialized with
// 	the value of the parameter ’content’.The variable
// ’next’ is initialized to NULL.
// void test_ft_lstnew_basic(void)
// {
// 	printf("Test 1: Creating a new node with content 'Hello'\n");

// 	char *content = "Hello";
// 	t_list *node = ft_lstnew(content);

// 	// Check if the node is created correctly, content is set, and 'next' is NULL
// 	if (node != NULL && node->content == content && node->next == NULL)
// 	{
// 		printf("Test 1: PASSED\n");
// 		printf("content: %s next: %p \n", (char *)node->content, node->next);
// 	}
// 	else
// 	{
// 		printf("Test 1: FAILED\n");
// 	}

// 	free(node);
// }

// int main(void)
// {
// 	test_ft_lstnew_basic();
// 	return (0);
// }
// #################################################
// ft_lstadd_front
// Adds the node ’new’ at the beginning of the list.
// void test_ft_lstadd_front_basic(void)
// {
// 	printf("Test 1: Add a node at the beginning of a list\n");

// 	t_list *list = ft_lstnew("First");
// 	t_list *new_node = ft_lstnew("Second");

// 	printf("list: content: '%s',next: %p\n", (char *)list->content, list->next);
// 	// Add new_node at the front of the list
// 	ft_lstadd_front(&list, new_node);

// 	// Check if the new node is at the front
// 	if (list != NULL && strcmp(list->content, "Second") == 0 && list->next != NULL && strcmp(list->next->content, "First") == 0)
// 	{
// 		printf("Test 1: PASSED\n");
// 		printf("node1: content: '%s',next: %p\n", (char *)list->content, list->next);
// 		printf("node2: content: '%s',next: %p\n", (char *)list->next->content, list->next->next);
// 	}
// 	else
// 	{
// 		printf("Test 1: FAILED\n");
// 	}

// 	// Free the allocated memory
// 	free(list->next);
// 	free(list);
// }

// void test_ft_lstadd_front_empty_list(void)
// {
// 	printf("Test 2: Add a node to an empty list\n");

// 	t_list *list = NULL;
// 	t_list *new_node = ft_lstnew("New Node");

// 	// Add new_node to the empty list
// 	ft_lstadd_front(&list, new_node);

// 	// Check if the list contains the new node
// 	if (list != NULL && strcmp(list->content, "New Node") == 0 && list->next == NULL)
// 	{
// 		printf("Test 2: PASSED\n");
// 		printf("node1: content: '%s',next: %p\n", (char *)list->content, list->next);
// 		printf("node2: content: '%s',next: %p\n", (char *)list->next->content, list->next->next);
// 	}
// 	else
// 	{
// 		printf("Test 2: FAILED\n");
// 	}

// 	// Free the allocated memory
// 	free(list);
// }

// int main(void)
// {
// 	test_ft_lstadd_front_basic();
// 	test_ft_lstadd_front_empty_list();
// 	return (0);
// }
// #############################################################
// ft_lstsize
// Counts the number of nodes in a list.
// void test_ft_lstsize_empty_list(void)
// {
// 	printf("Test 1: Empty list\n");

// 	t_list *list = NULL;

// 	int size = ft_lstsize(list);
// 	if (size == 0)
// 		printf("Test 1: PASSED (Size = %d)\n", size);
// 	else
// 		printf("Test 1: FAILED (Expected Size = 0, Got = %d)\n", size);
// }
// void test_ft_lstsize_multiple_nodes(void)
// {
// 	printf("Test 3: List with multiple nodes\n");

// 	t_list *node1 = ft_lstnew("Node 1");
// 	t_list *node2 = ft_lstnew(NULL);
// 	t_list *node3 = ft_lstnew("Node 3");

// 	// Link the nodes
// 	node1->next = node2;
// 	node2->next = node3;

// 	int size = ft_lstsize(node1);
// 	if (size == 3)
// 	{
// 		printf("Test 3: PASSED (Size = %d)\n", size);
// 		printf("node1: content: '%s',next: %p\n", (char *)node1->content, node1->next);
// 		printf("node2: content: '%s',next: %p\n", (char *)node1->next->content, node1->next->next);
// 		printf("node3: content: '%s',next: %p\n", (char *)node1->next->next->content, node1->next->next->next);
// 	}
// 	else
// 		printf("Test 3: FAILED (Expected Size = 3, Got = %d)\n", size);

// 	// Free allocated memory
// 	free(node3);
// 	free(node2);
// 	free(node1);
// }
// int main(void)
// {
// 	test_ft_lstsize_empty_list();
// 	test_ft_lstsize_multiple_nodes();
// 	return (0);
// }
// #############################################################
// ft_lstlast
// Returns the last node of the list.
// void test_ft_lstlast_empty_list(void)
// {
// 	printf("Test 1: Empty list\n");

// 	t_list *list = NULL;

// 	t_list *last = ft_lstlast(list);
// 	if (last == NULL)
// 		printf("Test 1: PASSED (Last = NULL)\n");
// 	else
// 		printf("Test 1: FAILED (Expected Last = NULL, Got = %p)\n", last);
// }
// void test_ft_lstlast_multiple_nodes(void)
// {
// 	printf("Test 3: List with multiple nodes\n");

// 	t_list *node1 = ft_lstnew("Node 1");
// 	t_list *node2 = ft_lstnew(NULL);
// 	t_list *node3 = ft_lstnew("Node 3");

// 	// Link the nodes
// 	node1->next = node2;
// 	node2->next = node3;

// 	t_list *last = ft_lstlast(node1);
// 	if (last != NULL && strcmp((char *)last->content, "Node 3") == 0)
// 		printf("Test 3: PASSED (Last = %s)\n", (char *)last->content);
// 	else
// 		printf("Test 3: FAILED (Expected Last = Node 3, Got = %p)\n", last);

// 	// Free allocated memory
// 	free(node3);
// 	free(node2);
// 	free(node1);
// }
// int main(void)
// {
// 	test_ft_lstlast_empty_list();
// 	test_ft_lstlast_multiple_nodes();
// 	return (0);
// }
// ######################################################
// ft_lstadd_back
// Adds the node ’new’ at the end of the list.
// Test 1: Add a new node to an empty list
// void test_ft_lstadd_back_empty_list(void)
// {
// 	printf("Test 1: Add a new node to an empty list\n");

// 	t_list *list = NULL;
// 	t_list *new_node = ft_lstnew("New Node");

// 	ft_lstadd_back(&list, new_node);

// 	if (list != NULL && list->content != NULL && strcmp((char *)list->content, "New Node") == 0)
// 	{
// 		printf("Test 1: PASSED (List = '%s')\n", (char *)list->content);
// 		printf("node1: content: '%s',next: %p\n", (char *)list->content, list->next);
// 	}
// 	else
// 		printf("Test 1: FAILED\n");

// 	free(new_node);
// }
// void test_ft_lstadd_back_multiple_nodes(void)
// {
// 	printf("Test 2: Add a new node to a list with multiple nodes\n");

// 	t_list *node1 = ft_lstnew("Node 1");
// 	t_list *node2 = ft_lstnew("Node 2");
// 	t_list *new_node = ft_lstnew("Node 3");

// 	// Link the first two nodes
// 	node1->next = node2;

// 	ft_lstadd_back(&node1, new_node);

// 	if (node1 != NULL && node2->next != NULL && strcmp((char *)node2->next->content, "Node 3") == 0)
// 	{
// 		printf("Test 2: PASSED (List = 'Node 1 -> Node 2 -> Node 3')\n");
// 		printf("node1: content: '%s',next: %p\n", (char *)node1->content, node1->next);
// 		printf("node2: content: '%s',next: %p\n", (char *)node1->next->content, node1->next->next);
// 		printf("node3: content: '%s',next: %p\n", (char *)node1->next->next->content, node1->next->next->next);
// 	}
// 	else
// 		printf("Test 2: FAILED\n");

// 	free(new_node);
// 	free(node2);
// 	free(node1);
// }
// int main(void)
// {
// 	test_ft_lstadd_back_empty_list();
// 	test_ft_lstadd_back_multiple_nodes();
// 	return (0);
// }
// #######################################################
// ft_lstdelone
// Takes as a parameter a node and frees the memory of
// the node’s content using the function ’del’ given
// 	as a parameter and free the node.The memory of
// ’next’ must not be freed.
// Test 1: Delete a node with valid content
// Helper function to delete the content of a node
// void del_function(void *content)
// {
// 	if (content != NULL)
// 	{
// 		printf("Deleting content: %s\n", (char *)content);
// 		free(content); // Free the content of the node
// 	}
// }
// // Test 1: Delete a node with valid content
// void test_ft_lstdelone_valid_node(void)
// {
// 	printf("Test 1: Delete a node with valid content\n");
// 	char *content = strdup("Node Content"); // Duplicate string to simulate dynamically allocated content
// 	t_list *node = ft_lstnew(content);
// 	ft_lstdelone(node, del_function);
// 	printf("Test 1: PASSED (Node deleted successfully)\n");
// }

// // Test 2: Delete a node with NULL content
// void test_ft_lstdelone_null_content(void)
// {
// 	printf("Test 2: Delete a node with NULL content\n");
// 	t_list *node = ft_lstnew(NULL);
// 	ft_lstdelone(node, del_function);
// 	printf("Test 2: PASSED (Node with NULL content deleted successfully)\n");
// }

// // Test 3: Delete a NULL node
// void test_ft_lstdelone_null_node(void)
// {
// 	printf("Test 3: Delete a NULL node\n");
// 	ft_lstdelone(NULL, del_function);
// 	printf("Test 3: PASSED (No crash when deleting a NULL node)\n");
// }

// int main(void)
// {
// 	printf("Testing ft_lstdelone:\n");
// 	test_ft_lstdelone_valid_node();
// 	test_ft_lstdelone_null_content();
// 	test_ft_lstdelone_null_node();
// 	return (0);
// }
// ###############################################
// ft_lstclear
// Deletes and frees the given node and every
// successor of that node, using the function ’del’ and free(3).Finally, the pointer to the list must be set to NULL.
// Helper function to delete the content of a node
// void del_function(void *content)
// {
// 	if (content != NULL)
// 	{
// 		printf("Deleting content: %s\n", (char *)content);
// 		free(content);
// 	}
// }

// // Test 1: Clear a list with multiple nodes
// void test_ft_lstclear_multiple_nodes(void)
// {
// 	printf("Test 1: Clear a list with multiple nodes\n");

// 	// Create a list with multiple dynamically allocated nodes
// 	t_list *node1 = ft_lstnew(strdup("Node 1"));
// 	t_list *node2 = ft_lstnew(strdup("Node 2"));
// 	t_list *node3 = ft_lstnew(strdup("Node 3"));
// 	node1->next = node2;
// 	node2->next = node3;
// 	ft_lstclear(&node1, del_function);
// 	if (node1 == NULL)
// 		printf("Test 1: PASSED (List cleared and pointer set to NULL)\n");
// 	else
// 		printf("Test 1: FAILED (Pointer not set to NULL)\n");
// }

// // Test 2: Clear an empty list
// void test_ft_lstclear_empty_list(void)
// {
// 	printf("Test 2: Clear an empty list\n");
// 	t_list *list = NULL;
// 	ft_lstclear(&list, del_function);
// 	if (list == NULL)
// 		printf("Test 2: PASSED (No crash and pointer remains NULL)\n");
// 	else
// 		printf("Test 2: FAILED (Pointer modified unexpectedly)\n");
// }

// // Test 3: Clear a list with a single node
// void test_ft_lstclear_single_node(void)
// {
// 	printf("Test 3: Clear a list with a single node\n");
// 	t_list *node = ft_lstnew(strdup("Single Node"));
// 	ft_lstclear(&node, del_function);
// 	if (node == NULL)
// 		printf("Test 3: PASSED (List cleared and pointer set to NULL)\n");
// 	else
// 		printf("Test 3: FAILED (Pointer not set to NULL)\n");
// }

// // Test 4: Clear a list with NULL content
// void test_ft_lstclear_null_content(void)
// {
// 	printf("Test 4: Clear a list with NULL content\n");
// 	t_list *node1 = ft_lstnew(NULL);
// 	t_list *node2 = ft_lstnew(NULL);
// 	node1->next = node2;
// 	ft_lstclear(&node1, del_function);
// 	if (node1 == NULL)
// 		printf("Test 4: PASSED (List cleared and pointer set to NULL)\n");
// 	else
// 		printf("Test 4: FAILED (Pointer not set to NULL)\n");
// }

// // Test 5: Pass a NULL pointer to the list
// void test_ft_lstclear_null_pointer(void)
// {
// 	printf("Test 5: Pass a NULL pointer to the list\n");
// 	t_list **list = NULL;
// 	ft_lstclear(list, del_function);
// 	printf("Test 5: PASSED (No crash when NULL pointer passed)\n");
// }

// int main(void)
// {
// 	printf("Testing ft_lstclear:\n");
// 	test_ft_lstclear_multiple_nodes();
// 	test_ft_lstclear_empty_list();
// 	test_ft_lstclear_single_node();
// 	test_ft_lstclear_null_content();
// 	test_ft_lstclear_null_pointer();

// 	return 0;
// }
// ############################################################
// ft_lstiter
// Iterates the list ’lst’ and applies the function ’f’ on the content of each node.
// Helper function to apply to each node's content
// void print_content(void *content)
// {
// 	if (content != NULL)
// 		printf("Content: %s\n", (char *)content);
// }

// // Another helper function to modify content
// void uppercase_content(void *content)
// {
// 	if (content != NULL)
// 	{
// 		char *str = (char *)content;
// 		while (*str)
// 		{
// 			if (*str >= 'a' && *str <= 'z')
// 				*str -= 32; // Convert lowercase to uppercase
// 			str++;
// 		}
// 	}
// }

// // Test 1: Iterate over a list with multiple nodes
// void test_ft_lstiter_multiple_nodes(void)
// {
// 	printf("Test 1: Iterate over a list with multiple nodes\n");

// 	t_list *node1 = ft_lstnew(strdup("node 1"));
// 	t_list *node2 = ft_lstnew(strdup("node 2"));
// 	t_list *node3 = ft_lstnew(strdup("node 3"));

// 	node1->next = node2;
// 	node2->next = node3;

// 	ft_lstiter(node1, print_content);

// 	// Free allocated memory
// 	ft_lstclear(&node1, free);
// }

// // Test 2: Modify content of each node
// void test_ft_lstiter_modify_content(void)
// {
// 	printf("Test 2: Modify content of each node\n");

// 	t_list *node1 = ft_lstnew(strdup("lowercase 1"));
// 	t_list *node2 = ft_lstnew(strdup("lowercase 2"));
// 	t_list *node3 = ft_lstnew(strdup("lowercase 3"));

// 	node1->next = node2;
// 	node2->next = node3;

// 	printf("Before modification:\n");
// 	ft_lstiter(node1, print_content);

// 	ft_lstiter(node1, uppercase_content);

// 	printf("After modification:\n");
// 	ft_lstiter(node1, print_content);

// 	// Free allocated memory
// 	ft_lstclear(&node1, free);
// }

// // Test 3: Iterate over an empty list
// void test_ft_lstiter_empty_list(void)
// {
// 	printf("Test 3: Iterate over an empty list\n");

// 	t_list *list = NULL;

// 	ft_lstiter(list, print_content);

// 	printf("Test 3: PASSED (No crash on empty list)\n");
// }

// // Test 4: Single node in the list
// void test_ft_lstiter_single_node(void)
// {
// 	printf("Test 4: Single node in the list\n");

// 	t_list *node = ft_lstnew(strdup("single node"));

// 	ft_lstiter(node, print_content);

// 	// Free allocated memory
// 	ft_lstclear(&node, free);
// }

// int main(void)
// {
// 	printf("Testing ft_lstiter:\n");

// 	test_ft_lstiter_multiple_nodes();
// 	test_ft_lstiter_modify_content();
// 	test_ft_lstiter_empty_list();
// 	test_ft_lstiter_single_node();

// 	return 0;
// }
// #########################################################
// ft_lstmap
// Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node.Creates a new list resulting of the successive applications of
// 	the function ’f’.The ’del’ function is used to delete the content of a node if needed.
// Helper function to apply to each node's content (creates a new string with uppercase content)
// void *duplicate_uppercase_content(void *content)
// {
// 	if (!content)
// 		return NULL;

// 	char *str = (char *)content;
// 	char *new_str = strdup(str);
// 	if (!new_str)
// 		return NULL;

// 	for (int i = 0; new_str[i]; i++)
// 	{
// 		if (new_str[i] >= 'a' && new_str[i] <= 'z')
// 			new_str[i] -= 32; // Convert to uppercase
// 	}
// 	return new_str;
// }

// // Helper function to free node content
// void free_content(void *content)
// {
// 	free(content);
// }

// // Test 1: Map a function over a list with multiple nodes
// void test_ft_lstmap_multiple_nodes(void)
// {
// 	printf("Test 1: Map a function over a list with multiple nodes\n");

// 	t_list *node1 = ft_lstnew(strdup("node 1"));
// 	t_list *node2 = ft_lstnew(strdup("node 2"));
// 	t_list *node3 = ft_lstnew(strdup("node 3"));

// 	node1->next = node2;
// 	node2->next = node3;

// 	t_list *new_list = ft_lstmap(node1, duplicate_uppercase_content, free_content);

// 	// Verify the new list
// 	t_list *current = new_list;
// 	while (current)
// 	{
// 		printf("Mapped content: %s\n", (char *)current->content);
// 		current = current->next;
// 	}

// 	// Free both lists
// 	ft_lstclear(&node1, free_content);
// 	ft_lstclear(&new_list, free_content);
// }

// // Test 2: Map a function over an empty list
// void test_ft_lstmap_empty_list(void)
// {
// 	printf("Test 2: Map a function over an empty list\n");

// 	t_list *empty_list = NULL;

// 	t_list *new_list = ft_lstmap(empty_list, duplicate_uppercase_content, free_content);

// 	if (new_list == NULL)
// 		printf("Test 2: PASSED (Returned NULL for empty list)\n");
// 	else
// 		printf("Test 2: FAILED\n");
// }

// // Test 3: Map a function where memory allocation fails
// void test_ft_lstmap_allocation_failure(void)
// {
// 	printf("Test 3: Map a function where memory allocation fails\n");

// 	// Mock a function that always returns NULL
// 	void *mock_failure_function(void *content)
// 	{
// 		(void)content;
// 		return NULL;
// 	}

// 	t_list *node1 = ft_lstnew(strdup("node 1"));
// 	t_list *node2 = ft_lstnew(strdup("node 2"));

// 	node1->next = node2;

// 	t_list *new_list = ft_lstmap(node1, mock_failure_function, free_content);

// 	if (new_list == NULL)
// 		printf("Test 3: PASSED (Returned NULL on allocation failure)\n");
// 	else
// 		printf("Test 3: FAILED\n");

// 	// Free original list
// 	ft_lstclear(&node1, free_content);
// }

// // Test 4: Map a function over a single-node list
// void test_ft_lstmap_single_node(void)
// {
// 	printf("Test 4: Map a function over a single-node list\n");

// 	t_list *node = ft_lstnew(strdup("single node"));

// 	t_list *new_list = ft_lstmap(node, duplicate_uppercase_content, free_content);

// 	// Verify the new list
// 	if (new_list != NULL && new_list->content != NULL)
// 		printf("Mapped content: %s\n", (char *)new_list->content);

// 	// Free both lists
// 	ft_lstclear(&node, free_content);
// 	ft_lstclear(&new_list, free_content);
// }

// // Test 5: Handle NULL function pointer for `f`
// void test_ft_lstmap_null_function(void)
// {
// 	printf("Test 5: Handle NULL function pointer for `f`\n");

// 	t_list *node1 = ft_lstnew(strdup("node"));

// 	t_list *new_list = ft_lstmap(node1, NULL, free_content);

// 	if (new_list == NULL)
// 		printf("Test 5: PASSED (Returned NULL when `f` is NULL)\n");
// 	else
// 		printf("Test 5: FAILED\n");

// 	// Free original list
// 	ft_lstclear(&node1, free_content);
// }

// int main(void)
// {
// 	printf("Testing ft_lstmap:\n");

// 	test_ft_lstmap_multiple_nodes();
// 	test_ft_lstmap_empty_list();
// 	test_ft_lstmap_allocation_failure();
// 	test_ft_lstmap_single_node();
// 	test_ft_lstmap_null_function();

// 	return 0;
// }