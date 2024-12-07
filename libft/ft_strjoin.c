/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:39:39 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/07 13:40:05 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
// #include <stdio.h>
#include <stdlib.h>

static size_t ft_strlen(char *str)
{
	size_t len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
char *ft_strjoin(const char *s1, const char *s2)
{
	size_t len_s1;
	size_t len_s2;
	char *new_str;
	size_t i;

	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	new_str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < (len_s1))
	{
		new_str[i] = s1[i];
		i++;
	}
	while ((i - len_s1) < len_s2)
	{
		new_str[i] = s2[i - len_s1];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// int main(void)
// {
// 	char *s1 = "Hello";
// 	char *s2 = " World!";
// 	printf("%s\n", ft_strjoin(s1, s2));
// 	return (0);
// }
