/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:15:22 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/11/12 21:41:19 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}

int	process_split_argument(char *arg, t_list **node)
{
	char	**split_args;
	t_list	*tmp_node;
	int		j;
	int		value;

	split_args = ft_split(arg, ' ');
	if (!split_args)
		return (0);
	j = 0;
	while (split_args[j])
	{
		value = ft_atoi_safe(split_args[j], node);
		tmp_node = ft_lstnew(value);
		if (!tmp_node)
		{
			ft_free_split(split_args);
			ft_lstclear(node);
			return (0);
		}
		ft_lstadd_back(node, tmp_node);
		j++;
	}
	ft_free_split(split_args);
	return (1);
}

int	process_single_argument(char *arg, t_list **node)
{
	t_list	*tmp_node;
	int		value;

	value = ft_atoi_safe(arg, node);
	tmp_node = ft_lstnew(value);
	if (!tmp_node)
	{
		ft_lstclear(node);
		return (0);
	}
	ft_lstadd_back(node, tmp_node);
	return (1);
}

// Convert strings to integers
t_list	*parse_numbers(int argc, char **argv)
{
	t_list	*node;
	int		i;

	node = NULL;
	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			if (!process_split_argument(argv[i], &node))
				return (NULL);
		}
		else
		{
			if (!process_single_argument(argv[i], &node))
				return (NULL);
		}
		i++;
	}
	return (node);
}
