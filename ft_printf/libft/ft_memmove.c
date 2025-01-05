/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:15:27 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/16 17:42:23 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	if (dest_ptr > src_ptr)
	{
		while (n--)
			dest_ptr[n] = src_ptr[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dest_ptr[i] = src_ptr[i];
			i++;
		}
	}
	return (dest);
}
