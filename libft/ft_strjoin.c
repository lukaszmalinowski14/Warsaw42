/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:39:39 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/17 15:16:46 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	if (dest == NULL && src == NULL && len != 0)
		return (NULL);
	i = 0;
	while (i < len)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*new_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	new_str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (new_str != NULL)
	{
		ft_memcpy(new_str, s1, len_s1);
		ft_memcpy(new_str + len_s1, s2, len_s2);
		new_str[len_s1 + len_s2] = '\0';
	}
	return (new_str);
}
