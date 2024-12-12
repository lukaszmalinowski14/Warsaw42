/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:19:39 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/12 19:57:26 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>

static int len(long nb)
{
	int len = 0;
	if (nb <= 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}
char *ft_itoa(int n)
{
	char *str;
	int i;
	long nb;

	nb = n;
	i = len(nb);
	if (!(str = (char *)malloc(i + 1)))
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[i] = 48 + (nb % 10);
		nb /= 10;
		i--;
	}
	return (str);
}

// int main(void)
// {
// 	int e = -1;
// 	printf("%s\n", ft_itoa(e));
// 	return (0);
// }
