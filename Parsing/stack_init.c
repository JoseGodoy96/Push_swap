/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:03:47 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/11/12 22:31:30 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Error exit
void	error_exit(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}

// Create initial stack A
t_list	*init_stack_a(int argc, char **argv)
{
	t_list	*node;

	if (argc == 1)
		error_exit();
	node = parse_numbers(argc, argv);
	if (!node)
		error_exit();
	if (check_duplicates(node) == true)
	{
		ft_lstclear(&node);
		error_exit();
	}
	return (node);
}

// Create empty stack B
t_list	*init_stack_b(void)
{
	return (NULL);
}
