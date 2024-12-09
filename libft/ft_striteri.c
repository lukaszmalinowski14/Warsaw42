/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:06:20 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/07 22:31:48 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>

// static void my_function(unsigned int i, char *c)
// {
// 	*c = (*c + i % 26);
// }
void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;

	if (!s || !f)
		return;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// int main(void)
// {
// 	char s[] = "Hello";
// 	printf("Original string: %s\n", s);
// 	ft_striteri(s, my_function);
// 	printf("Modified string: %s\n", s);
// 	return (0);
// }
