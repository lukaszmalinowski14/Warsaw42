/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:19:36 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/13 23:57:12 by lmalinow         ###   ########.fr       */
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

// test ft_bzero
int main()
{
	char str1[] = "Hello World!";
	char str2[] = "Hello World!";

	printf("before ft_bzero: %s\n", str1);
	ft_bzero(str1, 5);
	printf("after ft_bzero: %s\n", str1);
	for (int i = 0; i < (int)sizeof(str1); i++)
	{
		if (str1[i] == '\0')
		{
			printf("\\0 ");
		}
		else
		{
			printf("%c ", str1[i]);
		}
	}
	printf("\n");

	printf("before bzero: %s\n", str2);
	bzero(str2, 5);
	printf("after bzero: %s\n", str2);
	for (int i = 0; i < (int)sizeof(str1); i++)
	{
		if (str1[i] == '\0')
		{
			printf("\\0 ");
		}
		else
		{
			printf("%c ", str1[i]);
		}
	}
	printf("\n");
	return (0);
}
