/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:17:49 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/03 15:42:34 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>  // for size_t

void	*ft_memset(void *ptr, int value, size_t n)
{
	unsigned char	*byte_ptr;
	unsigned char	byte_value;
	size_t	i;

	byte_ptr = (unsigned char *)ptr;
	byte_value = (unsigned char)value;
	i = 0;


	while (i < n)
	{
		byte_ptr[i] = byte_value;
		i++;
	}

	return (ptr);
}
