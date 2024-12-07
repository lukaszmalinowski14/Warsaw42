/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:04:17 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/06 19:19:41 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>

int ft_atoi(const char *str)
{
	int result;
	int sign;

	sign = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
		   *str == '\v' || *str == '\f' || *str == '\r')
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign = -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

// int main(void)
// {
// 	char *str = "   -345345";
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// 	return (0);
// }
