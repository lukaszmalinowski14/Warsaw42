/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:58:37 by lmalinow          #+#    #+#             */
/*   Updated: 2025/02/23 19:05:28 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int len(long nb)
{
	int i;

	i = (nb <= 0);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

// // TO REMOVE #################
// char *ft_itoa(int n)
// {
// 	char *str;
// 	long nb;
// 	int i;

// 	nb = n;
// 	i = len(nb);
// 	str = (char *)malloc(i + 1);
// 	if (!str)
// 		return (NULL);
// 	str[i--] = '\0';
// 	if (nb < 0)
// 	{
// 		str[0] = '-';
// 		nb = -nb;
// 	}
// 	while (i >= 0 && nb > 0)
// 	{
// 		str[i--] = '0' + (nb % 10);
// 		nb /= 10;
// 	}
// 	if (n == 0)
// 		str[0] = '0';
// 	return (str);
// }

// // TO REMOVE ####################################
// size_t ft_strlen(char *str)
// {
// 	size_t len;

// 	len = 0;
// 	while (str[len])
// 		len++;
// 	return (len);
// }
