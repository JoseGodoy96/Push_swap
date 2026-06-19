/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 00:03:40 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/11/12 22:30:48 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = init_stack_a(argc, argv);
	if (!stack_a)
		error_exit();
	stack_b = init_stack_b();
	push_swap(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
