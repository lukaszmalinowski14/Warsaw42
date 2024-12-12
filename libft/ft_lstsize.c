/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:22:05 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/12 22:11:32 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
// int main(void)
// {
// 	t_list *n1;
// 	t_list *n2;
// 	t_list *n3;

// 	n1 = malloc(sizeof(t_list));
// 	n1->content = "He";
// 	n2 = malloc(sizeof(t_list));
// 	n2->content = "ll";
// 	n3 = malloc(sizeof(t_list));
// 	n3->content = "o ";

// 	n1->next = n2;
// 	n2->next = n3;
// 	n3->next = NULL;
// 	printf("%d\n", ft_lstsize(n1));
// 	printf("%s\n", (char *)n1->content);
// free(n1);
// free(n2);
// free(n3);
// 	return (0);
// }
