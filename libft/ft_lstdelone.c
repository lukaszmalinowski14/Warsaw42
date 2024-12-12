/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:35:53 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/12 22:55:55 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void del(void *content)
// {
// 	// Example content deletion (e.g., if the content is a dynamically allocated string)
// 	free(content);
// }

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}

// int main(void)
// {
// 	t_list *n1;
// 	t_list *n2;
// 	t_list *n3;
// 	// t_list *n4;

// 	// n4 = malloc(sizeof(t_list));
// 	n1 = malloc(sizeof(t_list));
// 	n1->content = "He";
// 	n2 = malloc(sizeof(t_list));
// 	n2->content = "ll";
// 	n3 = malloc(sizeof(t_list));
// 	n3->content = "o ";
// 	// n4->content = "n4";

// 	n1->next = n2;
// 	n2->next = n3;
// 	n3->next = NULL;

// 	printf("%p\n", n3);
// 	ft_lstdelone(n3, del);
// 	printf("%p\n", n3);
// 	free(n1);
// 	free(n2);
// 	return (0);
// }
