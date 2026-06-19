/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:23:52 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/08/12 11:55:36 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack_a, int min_pos, int size)
{
	int	i;

	if (min_pos <= size / 2)
	{
		i = 0;
		while (i < min_pos)
		{
			ra(stack_a, 0);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size - min_pos)
		{
			rra(stack_a, 0);
			i++;
		}
	}
}

void	final_rotate(t_list **stack_a)
{
	t_list	*tmp_node;
	int		min_pos;
	int		min_index;
	int		size;

	place_position(*stack_a);
	tmp_node = *stack_a;
	min_index = INT_MAX;
	min_pos = 0;
	while (tmp_node != NULL)
	{
		if (tmp_node->index < min_index)
		{
			min_index = tmp_node->index;
			min_pos = tmp_node->position;
		}
		tmp_node = tmp_node->next;
	}
	size = ft_lstsize(*stack_a);
	rotate(stack_a, min_pos, size);
}

void	cost_algorithm(t_list **stack_a, t_list **stack_b)
{
	int		size_a;
	int		size_b;

	normalize_values(stack_a);
	size_a = ft_lstsize(*stack_a);
	while (size_a > 3)
	{
		pb(stack_a, stack_b);
		size_a--;
	}
	sort_three(stack_a);
	while (*stack_b != NULL)
	{
		place_position(*stack_a);
		place_position(*stack_b);
		size_a = ft_lstsize(*stack_a);
		size_b = ft_lstsize(*stack_b);
		cal_costs(*stack_a, *stack_b, size_a, size_b);
		execute_cheapest(stack_a, stack_b);
	}
	final_rotate(stack_a);
}
