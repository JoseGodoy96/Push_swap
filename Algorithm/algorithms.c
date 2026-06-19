/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 23:19:55 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/08/07 13:34:53 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, 0);
}

void	sort_three(t_list **stack_a)
{
	int	value1;
	int	value2;
	int	value3;

	value1 = (*stack_a)->value;
	value2 = (*stack_a)->next->value;
	value3 = (*stack_a)->next->next->value;
	if (value1 > value2 && value2 < value3 && value1 < value3)
		sa(stack_a, 0);
	else if (value1 < value2 && value2 > value3 && value1 > value3)
		rra(stack_a, 0);
	else if (value1 > value2 && value2 < value3 && value1 > value3)
		ra(stack_a, 0);
	else if (value1 < value2 && value2 > value3 && value1 < value3)
	{
		sa(stack_a, 0);
		ra(stack_a, 0);
	}
	else if (value1 > value2 && value2 > value3 && value1 > value3)
	{
		sa(stack_a, 0);
		rra(stack_a, 0);
	}
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (ft_is_sorted(*stack_a))
		return ;
	else if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else
		cost_algorithm(stack_a, stack_b);
}
