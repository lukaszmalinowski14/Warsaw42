/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:48:41 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/12 22:11:49 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
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
// 	printf("last %s\n", (char *)ft_lstlast(n1)->content);
// 	printf("first %s\n", (char *)n1->content);
// free(n1);
// free(n2);
// free(n3);
// 	return (0);
// }
