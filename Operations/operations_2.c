/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:09:59 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/07/31 21:05:42 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// A[1, 2, 3] -> A[3, 1, 2]
void	rra(t_list **node_a, int flag)
{
	t_list	*tail_node;
	t_list	*tmp_node;

	if (!node_a || !*node_a || !(*node_a)->next)
		return ;
	tmp_node = *node_a;
	while (tmp_node->next->next != NULL)
	{
		tmp_node = tmp_node->next;
	}
	tail_node = tmp_node->next;
	tmp_node->next = NULL;
	tail_node->prev = NULL;
	tail_node->next = *node_a;
	(*node_a)->prev = tail_node;
	(*node_a) = tail_node;
	if (flag == 0)
		write(1, "rra\n", 4);
}

// B[4, 5, 6] -> B[6, 4, 5]
void	rrb(t_list **node_b, int flag)
{
	t_list	*tail_node;
	t_list	*tmp_node;

	if (!node_b || !*node_b || !(*node_b)->next)
		return ;
	tmp_node = *node_b;
	while (tmp_node->next->next != NULL)
	{
		tmp_node = tmp_node->next;
	}
	tail_node = tmp_node->next;
	tmp_node->next = NULL;
	tail_node->prev = NULL;
	tail_node->next = *node_b;
	(*node_b)->prev = tail_node;
	(*node_b) = tail_node;
	if (flag == 0)
		write(1, "rrb\n", 4);
}

// A[1, 2, 3] -> A[3, 1, 2] B[4, 5, 6] -> B[6, 4, 5]
void	rrr(t_list **node_a, t_list **node_b)
{
	rra(node_a, 1);
	rrb(node_b, 1);
	write(1, "rrr\n", 4);
}
