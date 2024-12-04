/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:03:19 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/04 20:27:40 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strrchr(const char *s, int c)
{
	char *p;

	p = NULL;
	while (*s)
	{
		if (*s == (char)c)
			p = (char *)s;
		s++;
	}
	if (c == '\0')
		return (char *)s;

	return p;
}

// int main(void)
// {
// 	const char *str = "Hello, World!";
// 	char *result;

// 	result = ft_strrchr(str, 'r');
// 	if (result != NULL)
// 	{
// 		printf("Last occurance 'r' is on position: %ld\n", result - str);
// 	}
// 	else
// 	{
// 		printf(" 'o' doesn't occure in string.\n");
// 	}

// 	return (0);
// }
