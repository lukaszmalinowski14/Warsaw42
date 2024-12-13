/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:36:12 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/13 19:08:54 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static void ft_print_content(void *content)
// {
// 	printf("%s\n", (char *)content);
// }
void ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
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
// 	ft_lstiter(n1, ft_print_content);
// 	return (0);
// }
