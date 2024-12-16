/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:21:04 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/16 20:25:51 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

// static size_t	ft_ned_memory(char const *s, unsigned int start, size_t len)
// {
// 	size_t	to_end;
// 	size_t	str_len;

// 	str_len = ft_strlen((char *)s);
// 	to_end = str_len - start;
// 	if (to_end < len)
// 		return (to_end);
// 	return (len);

// }

// static char	*ft_error()
// {
// 	char	*new;

// 	new = malloc(1);
// 	if (!new)
// 		return (NULL);
// 	new[0] = '\0';
// 	return (new);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	size_t	s_len;
// 	size_t	s_mem;
// 	char	*new;

// 	if (s == NULL)
// 		return ((char *)ft_error);
// 	s_len = ft_strlen((char *)s);
// 	s_mem = ft_ned_memory((char *)s, start, len);
// 	i = 0;
// 	if (start >= s_len)
// 	{
// 		return ((char *)ft_error);
// 	}
// 	new = malloc((s_mem + 1) * sizeof(char));
// 	if (!new)
// 		return (NULL);
// 	while (i < len && s[start + i])
// 	{
// 		new[i] = s[start + i];
// 		i++;
// 	}
// 	new[i] = '\0';
// 	return (new);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	alloc_len;
	char	*substr;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (start >= s_len)
	{
		substr = ((char *)malloc(1));
		substr[0] = '\0';
		return (substr);
	}
	if (start + len > s_len)
	{
		alloc_len = s_len - start;
	}
	else
	{
		alloc_len = len;
	}
	substr = (char *)malloc(alloc_len + 1);
	if (!substr)
	{
		return (NULL);
	}
	ft_strncpy(substr, (char *)s + start, alloc_len);
	substr[alloc_len] = '\0';
	return (substr);
}

// int main (void)
// {
// 	char *str=ft_substr("HOLA MUNDO", 10, 5);		//ft_substr("HOLA MUNDO", 8, 5);
// 	printf("%s\n",str);
// 	ft_substr(NULL, 0, 2);
// 	return (0);
// }
