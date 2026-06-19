/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_algorithm_utils_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:24:42 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/08/07 13:37:37 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	absolute_value(int cost_a, int cost_b)
{
	int	a;
	int	b;
	int	total_cost;

	a = cost_a;
	b = cost_b;
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	total_cost = a + b;
	return (total_cost);
}

t_list	*get_cheapest_move(t_list *stack)
{
	t_list	*cheapest;
	int		min_cost;
	int		current_cost;

	cheapest = stack;
	min_cost = absolute_value(stack->cost_a, stack->cost_b);
	stack = stack->next;
	while (stack != NULL)
	{
		current_cost = absolute_value(stack->cost_a, stack->cost_b);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	return (cheapest);
}

void	double_rotations(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
		rr(stack_a, stack_b);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
	while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
	{
		rrr(stack_a, stack_b);
		cheapest->cost_a++;
		cheapest->cost_b++;
	}
}

void	single_rotations(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	while (cheapest->cost_a > 0)
	{
		ra(stack_a, 0);
		cheapest->cost_a--;
	}
	while (cheapest->cost_a < 0)
	{
		rra(stack_a, 0);
		cheapest->cost_a++;
	}
	while (cheapest->cost_b > 0)
	{
		rb(stack_b, 0);
		cheapest->cost_b--;
	}
	while (cheapest->cost_b < 0)
	{
		rrb(stack_b, 0);
		cheapest->cost_b++;
	}
}

void	execute_cheapest(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = get_cheapest_move(*stack_b);
	double_rotations(stack_a, stack_b, cheapest);
	single_rotations(stack_a, stack_b, cheapest);
	pa(stack_a, stack_b);
}
