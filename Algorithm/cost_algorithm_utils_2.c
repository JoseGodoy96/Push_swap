/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_algorithm_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:25:05 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/08/07 12:50:00 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize_values(t_list **stack)
{
	t_list	*tmp_node;
	t_list	*cpy_node;
	int		value;
	int		index;

	tmp_node = *stack;
	while (tmp_node != NULL)
	{
		cpy_node = *stack;
		value = tmp_node->value;
		index = 0;
		while (cpy_node != NULL)
		{
			if (value > cpy_node->value)
				index++;
			cpy_node = cpy_node->next;
		}
		tmp_node->index = index;
		tmp_node = tmp_node->next;
	}
}

void	place_position(t_list *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack->position = i;
		i++;
		stack = stack->next;
	}
}

int	final_ta(t_list *stack_a, t_list *tmp_node, int target, int best_index)
{
	if (best_index == INT_MAX)
	{
		tmp_node = stack_a;
		while (tmp_node != NULL)
		{
			if (tmp_node->index < best_index)
			{
				best_index = tmp_node->index;
				target = tmp_node->position;
			}
			tmp_node = tmp_node->next;
		}
	}
	return (target);
}

int	get_target(t_list *stack_a, int index_b)
{
	t_list	*tmp_node;
	int		target;
	int		best_index;

	tmp_node = stack_a;
	target = 0;
	best_index = INT_MAX;
	while (tmp_node != NULL)
	{
		if (tmp_node->index > index_b && tmp_node->index < best_index)
		{
			best_index = tmp_node->index;
			target = tmp_node->position;
		}
		tmp_node = tmp_node->next;
	}
	target = final_ta(stack_a, tmp_node, target, best_index);
	return (target);
}

void	cal_costs(t_list *stack_a, t_list *stack_b, int size_a, int size_b)
{
	t_list	*tmp_node;

	tmp_node = stack_b;
	while (tmp_node != NULL)
	{
		tmp_node->target = get_target(stack_a, tmp_node->index);
		if (tmp_node->position <= size_b / 2)
			tmp_node->cost_b = tmp_node->position;
		else
			tmp_node->cost_b = tmp_node->position - size_b;
		if (tmp_node->target <= size_a / 2)
			tmp_node->cost_a = tmp_node->target;
		else
			tmp_node->cost_a = tmp_node->target - size_a;
		tmp_node = tmp_node->next;
	}
}
