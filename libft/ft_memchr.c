/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:35:18 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/17 14:58:17 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_ptr;
	unsigned char	byte;

	byte = (unsigned char)c;
	s_ptr = (unsigned char *)s;
	while (n--)
	{
		if (byte == *s_ptr)
			return ((void *)s_ptr);
		s_ptr++;
	}
	return (NULL);
}
