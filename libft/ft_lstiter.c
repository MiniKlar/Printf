/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:29:03 by lomont            #+#    #+#             */
/*   Updated: 2024/11/13 03:09:16 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
// void ft_add30(void *c)
// 	{
// 		c = c + 30;
// 		return (c);
// 	}

// int	main(void)
// {
// 	t_list *node;
// 	int a;
// 	int *ptr;
	
// 	a = 60;
// 	ptr = &a;
// 	node = ft_lstnew(ptr);
// 	printf("%d\n", *(int *)node->content);
// 	ft_lstiter(node, ft_add30(*ptr));
// 	printf("%d\n", *(int *)node->content);
// }
