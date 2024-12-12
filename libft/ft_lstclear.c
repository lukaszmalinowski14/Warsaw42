/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:53:27 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/12 23:35:48 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void del(void *content)
// {
// 	// Example content deletion (e.g., if the content is a dynamically allocated string)
// 	free(content);
// }
void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	if (!del || !lst || !*lst)
		return;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}
// int main(void)
// {
// 	t_list *n1;
// 	t_list *n2;
// 	t_list *n3;
// 	n1 = malloc(sizeof(t_list));
// 	n2 = malloc(sizeof(t_list));
// 	n3 = malloc(sizeof(t_list));
// 	n1->content = malloc(strlen("He") + 1);
// 	n2->content = malloc(strlen("ll") + 1);
// 	n3->content = malloc(strlen("o!") + 1);
// 	n1->next = n2;
// 	n2->next = n3;
// 	n3->next = NULL;
// 	// Print before clearing the list
// 	printf("Before clearing the list\n");
// 	printf("n1: %p, n2: %p, n3: %p\n", (void *)n1, (void *)n2, (void *)n3);
// 	ft_lstclear(&n1, del);
// 	// Print after clearing the list
// 	// Drukowanie po czyszczeniu listy
// 	printf("After clearing the list\n");
// 	printf("n1: %p\n", (void *)n1);
// 	printf("n1 next: %p\n", (void *)n1->next);
// 	return (0);
// }
