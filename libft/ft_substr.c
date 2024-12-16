/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:21:04 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/16 22:19:04 by lmalinow         ###   ########.fr       */
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

static char	*ft_strncpy(char *dest, char *src, unsigned int n)
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

static size_t ft_alloc_len(unsigned int start, size_t len, size_t s_len)
{
	size_t	alloc_len;
	
	if (start + len > s_len)
	{
		alloc_len = s_len - start;
	}
	else
	{
		alloc_len = len;
	}
	return (alloc_len);
}

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
	alloc_len = ft_alloc_len(start, len, s_len);
	substr = (char *)malloc(alloc_len + 1);
	if (!substr)
	{
		return (NULL);
	}
	ft_strncpy(substr, (char *)s + start, alloc_len);
	substr[alloc_len] = '\0';
	return (substr);
}
