/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:09:37 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/17 15:07:03 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	void	*content;

	if (lst != NULL && f != NULL && del != NULL)
	{
		content = f(lst->content);
		result = ft_lstnew(content);
		if (result == NULL)
		{
			del(content);
			return (NULL);
		}
		if (lst->next != NULL)
		{
			result->next = ft_lstmap(lst->next, f, del);
			if (result->next == NULL)
			{
				ft_lstdelone(result, del);
				return (NULL);
			}
		}
		return (result);
	}
	return (NULL);
}
