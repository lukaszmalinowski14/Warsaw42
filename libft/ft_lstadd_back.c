/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:47:54 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/13 20:08:22 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *temp;

	if (!*lst)
	{
		*lst = new;
		return;
	}

	temp = *lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}

// int main(void)
// {
// 	t_list *n1;
// 	t_list *n2;
// 	t_list *n3;
// 	t_list *n4;

// 	n4 = malloc(sizeof(t_list));
// 	n1 = malloc(sizeof(t_list));
// 	n1->content = "He";
// 	n2 = malloc(sizeof(t_list));
// 	n2->content = "ll";
// 	n3 = malloc(sizeof(t_list));
// 	n3->content = "o ";
// 	n4->content = "n4";

// 	n1->next = n2;
// 	n2->next = NULL;
// 	ft_lstadd_back(&n1, n3);

// 	t_list *current = n1;
// 	while (current != NULL)
// 	{
// 		printf("%s\n", (char *)current->content);
// 		current = current->next;
// 	}
// 	free(n1);
// 	free(n2);
// 	free(n3);
// 	free(n4);
// 	return (0);
// }
