/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:21:04 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/06 20:39:21 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // for size_t
#include <stdlib.h>
// #include <stdio.h>

static size_t ft_strlen(char *str)
{
	size_t len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	size_t s_len;
	char *new;

	s_len = ft_strlen((char *)s);
	i = 0;
	if (start >= s_len)
	{
		new = malloc(1);
		if (!new)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (i < len && s[start + i])
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

// int main(void)
// {
// 	char *str = "Hello World!";
// 	printf("%s\n", ft_substr(str, 6, 15));
// 	return (0);
// }
