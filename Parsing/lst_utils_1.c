/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 21:38:19 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/08/07 07:55:35 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->position = 0;
	node->target = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp_node;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		temp_node = (*lst)->next;
		free(*lst);
		*lst = temp_node;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		(*lst)->prev = new;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp_node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp_node = *lst;
	while (temp_node->next != NULL)
	{
		temp_node = temp_node->next;
	}
	temp_node->next = new;
	new->prev = temp_node;
}
