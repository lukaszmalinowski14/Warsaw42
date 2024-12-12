/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:01:54 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/12 22:11:43 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
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
// 	n2->next = NULL;
// 	printf("first %s\n", (char *)n1->content);
// 	ft_lstadd_front(&n1, n3);
// 	printf("first %s\n", (char *)n1->content);
// 	printf("second %s\n", (char *)n1->next->content);
// free(n1);
// free(n2);
// free(n3);
// 	return (0);
// }
