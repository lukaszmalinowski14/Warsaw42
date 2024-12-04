/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:06:43 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/04 20:03:07 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>

char *ft_strchr(const char *s, int c)
{
	unsigned char d;

	d = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == d)
			return (char *)s;
		s++;
	}
	if (d == '\0')
		return (char *)s;
	return NULL;
}

// int main(void)
// {
// 	const char str[] = "Hello, World!";
// 	char ch = 'l';
// 	char *result = ft_strchr(str, ch);

// 	if (result)
// 	{
// 		write(1, result, 13); // Wypisze "World!"
// 		write(1, "\n", 1);
// 	}
// 	else
// 		write(1, "Not found", 9);

// 	return (0);
// }
