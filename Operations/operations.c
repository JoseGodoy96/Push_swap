/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:53:32 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/07/31 21:01:06 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// A[1, 2, 3] -> [2, 1, 3] 
void	sa(t_list **node_a, int flag)
{
	t_list	*swp_node;
	t_list	*tmp_node;

	if (!*node_a || !node_a || ((*node_a)->next == NULL))
		return ;
	tmp_node = (*node_a);
	swp_node = (*node_a)->next;
	tmp_node->next = swp_node->next;
	tmp_node->prev = swp_node;
	swp_node->next = tmp_node;
	swp_node->prev = NULL;
	if (tmp_node->next)
		tmp_node->next->prev = tmp_node;
	(*node_a) = swp_node;
	if (flag == 0)
		write(1, "sa\n", 3);
}

// B[1, 2, 3] -> [2, 1, 3] 
void	sb(t_list **node_b, int flag)
{
	t_list	*swp_node;
	t_list	*tmp_node;

	if (!*node_b || !node_b || ((*node_b)->next == NULL))
		return ;
	tmp_node = (*node_b);
	swp_node = (*node_b)->next;
	tmp_node->next = swp_node->next;
	tmp_node->prev = swp_node;
	swp_node->next = tmp_node;
	swp_node->prev = NULL;
	if (tmp_node->next)
		tmp_node->next->prev = tmp_node;
	(*node_b) = swp_node;
	if (flag == 0)
		write(1, "sb\n", 3);
}

// A[1, 2, 3] -> [2, 1, 3] 	B[1, 2, 3] -> [2, 1, 3] 
void	ss(t_list **node_a, t_list **node_b)
{
	sa(node_a, 1);
	sb(node_b, 1);
	write(1, "ss\n", 3);
}

// A[1, 2, 3] B[4, 5, 6] -> A[4, 1, 2, 3] B[5, 6]
void	pa(t_list **node_a, t_list **node_b)
{
	t_list	*tmp_node;

	if (!*node_b)
		return ;
	tmp_node = *node_b;
	*node_b = (*node_b)->next;
	if (*node_b)
		(*node_b)->prev = NULL;
	tmp_node->prev = NULL;
	tmp_node->next = *node_a;
	if (*node_a)
		(*node_a)->prev = tmp_node;
	*node_a = tmp_node;
	write(1, "pa\n", 3);
}

// B[1, 2, 3] A[4, 5, 6] -> B[4, 1, 2, 3] A[5, 6]
void	pb(t_list **node_a, t_list **node_b)
{
	t_list	*tmp_node;

	if (!*node_a)
		return ;
	tmp_node = *node_a;
	*node_a = (*node_a)->next;
	if (*node_a)
		(*node_a)->prev = NULL;
	tmp_node->prev = NULL;
	tmp_node->next = *node_b;
	if (*node_b)
		(*node_b)->prev = tmp_node;
	*node_b = tmp_node;
	write(1, "pb\n", 3);
}
