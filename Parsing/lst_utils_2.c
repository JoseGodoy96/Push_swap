/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 21:38:16 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/06/25 21:43:12 by jgodoy-m         ###   ########.fr       */
/*                             {
}                                               */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstremove_first(t_list **lst)
{
	t_list	*tmp_node;

	if (!lst || !*lst)
		return ;
	tmp_node = *lst;
	*lst = (*lst)->next;
	if (*lst)
		(*lst)->prev = NULL;
	free(tmp_node);
}

void	ft_lstremove_last(t_list **lst)
{
	t_list	*tmp_node;
	t_list	*lst_node;

	if (!lst || !*lst)
		return ;
	if ((*lst)->next == NULL)
	{
		free(*lst);
		*lst = NULL;
		return ;
	}
	lst_node = *lst;
	while (lst_node->next != NULL)
		lst_node = lst_node->next;
	tmp_node = lst_node->prev;
	tmp_node->next = NULL;
	free(lst_node);
}

bool	ft_is_sorted(t_list *lst)
{
	int	temp_value;

	temp_value = lst->value;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (temp_value > lst->value)
			return (false);
		temp_value = lst->value;
	}
	return (true);
}

int	ft_find_min(t_list *lst)
{
	int	min_value;

	if (!lst)
		return (INT_MAX);
	min_value = lst->value;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (min_value > lst->value)
			min_value = lst->value;
	}
	return (min_value);
}

int	ft_find_max(t_list *lst)
{
	int	max_value;

	if (!lst)
		return (INT_MIN);
	max_value = lst->value;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (max_value < lst->value)
			max_value = lst->value;
	}
	return (max_value);
}
