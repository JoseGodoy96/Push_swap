/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:03:50 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/11/12 22:31:34 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Error exit atoi
void	error_exit_atoi(t_list **node)
{
	write(2, "ERROR\n", 6);
	if (node)
		ft_lstclear(node);
	return ;
}

// Atoi safe for verify the args
int	ft_validation(char *str, int i, t_list **node)
{
	if (!str || !*str)
		error_exit_atoi(node);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	ft_atoi_safe(char *str, t_list **node)
{
	int		i;
	int		sign;
	long	value;

	sign = 1;
	value = 0;
	i = 0;
	i = ft_validation(str, i, node);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		error_exit_atoi(node);
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	value = value * sign;
	if (str[i] != '\0' || value > INT_MAX || value < INT_MIN)
		error_exit_atoi(node);
	return ((int)value);
}

// Check for duplicates
bool	check_duplicates(t_list *node)
{
	t_list	*tmp_node;
	int		value;
	int		compare;

	while (node->next != NULL)
	{
		tmp_node = node->next;
		value = node->value;
		while (tmp_node != NULL)
		{
			compare = tmp_node->value;
			if (value == compare)
				return (true);
			tmp_node = tmp_node->next;
		}
		node = node->next;
	}
	return (false);
}

// Free memory
void	free_stacks(t_list **node_a, t_list **node_b)
{
	if (node_a && *node_a)
		ft_lstclear(node_a);
	if (node_b && *node_b)
		ft_lstclear(node_b);
}
