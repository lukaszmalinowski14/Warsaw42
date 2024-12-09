/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:44:46 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/09 20:15:49 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <string.h>
// #include <stdio.h>

static size_t ft_strlen(char *str)
{
	size_t len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
// static char my_function(unsigned int i, char c)
// {
// 	return (c + i % 26); // Dodaje przesunięcie na podstawie indeksu
// }

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *result;
	unsigned int i;

	if (!s || !f)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// int main(void)
// {
// 	char *s = "Hello";
// 	char *result;

// 	result = ft_strmapi(s, my_function);
// 	if (result)
// 	{
// 		printf("Original string: %s\n", s);
// 		printf("Modified string: %s\n", result);
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Memory allocation failed.\n");
// 	}
// 	return (0);
// }
