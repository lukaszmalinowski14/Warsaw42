/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:09:37 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/15 18:53:17 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static void *ft_edit_content(void *content)
// {
// 	*(int *)content += 4;
// 	return content;
// }
// static void ft_del_node(void *content)
// {
// 	free(content);
// }
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *first;
	t_list *new;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		if (!(new = ft_lstnew((*f)(lst->content))))
		{
			while (first)
			{
				new = first->next;
				(*del)(first->content);
				free(first);
				first = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
// int main(void)
// {
// 	t_list *n1;
// 	t_list *n2;
// 	t_list *n3;
// 	t_list *n4;
// 	n4 = NULL;

// 	// Tworzymy węzły listy
// 	n1 = malloc(sizeof(t_list));
// 	n1->content = malloc(sizeof(int));
// 	*(int *)n1->content = 5;

// 	n2 = malloc(sizeof(t_list));
// 	n2->content = malloc(sizeof(int));
// 	*(int *)n2->content = 6;

// 	n3 = malloc(sizeof(t_list));
// 	n3->content = malloc(sizeof(int));
// 	*(int *)n3->content = 8;

// 	n1->next = n2;
// 	n2->next = n3;
// 	n3->next = NULL;

// 	// Modyfikujemy listę
// 	n4 = ft_lstmap(n1, ft_edit_content, ft_del_node);

// 	// Wyświetlamy zmodyfikowaną zawartość listy
// 	t_list *current = n4;
// 	while (current)
// 	{
// 		printf("%d\n", *(int *)current->content); // Wyświetlamy zawartość węzła
// 		current = current->next;
// 	}

// 	// Zwalniamy pamięć
// 	// ft_lstclear(&n4, ft_del_node);

// 	return (0);
// }