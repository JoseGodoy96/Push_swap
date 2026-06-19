/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:24:15 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/07/31 21:02:34 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// A[1, 2, 3] -> A[2, 3, 1]
void	ra(t_list **node_a, int flag)
{
	t_list	*tmp_node;
	t_list	*head_node;

	if (!node_a || !*node_a || !(*node_a)->next)
		return ;
	head_node = *node_a;
	*node_a = (*node_a)->next;
	if (*node_a)
		(*node_a)->prev = NULL;
	tmp_node = *node_a;
	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;
	tmp_node->next = head_node;
	head_node->prev = tmp_node;
	head_node->next = NULL;
	if (flag == 0)
		write(1, "ra\n", 3);
}

// B[1, 2, 3] -> B[2, 3, 1]
void	rb(t_list **node_b, int flag)
{
	t_list	*tmp_node;
	t_list	*head_node;

	if (!node_b || !*node_b || !(*node_b)->next)
		return ;
	head_node = *node_b;
	*node_b = (*node_b)->next;
	if (*node_b)
		(*node_b)->prev = NULL;
	tmp_node = *node_b;
	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;
	tmp_node->next = head_node;
	head_node->prev = tmp_node;
	head_node->next = NULL;
	if (flag == 0)
		write(1, "rb\n", 3);
}

// A[1, 2, 3] -> A[2, 3, 1] B[4, 5, 6] -> B[5, 6, 4]
void	rr(t_list **node_a, t_list **node_b)
{
	ra(node_a, 1);
	rb(node_b, 1);
	write(1, "rr\n", 3);
}
