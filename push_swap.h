/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:57:18 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/11/12 22:31:53 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				position;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_list	*prev;
	struct s_list	*next;
}		t_list;

// lst_utils.c
t_list	*ft_lstnew(int value);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstremove_first(t_list **lst);
void	ft_lstremove_last(t_list **lst);
bool	ft_is_sorted(t_list *lst);
int		ft_find_min(t_list *lst);
int		ft_find_max(t_list *lst);
// stack_init.c
void	error_exit(void);
t_list	*init_stack_a(int argc, char **argv);
t_list	*init_stack_b(void);
// stack_init_utils_1.c
void	error_exit_atoi(t_list **node);
int		ft_validation(char *str, int i, t_list **node);
int		ft_atoi_safe(char *str, t_list **node);
bool	check_duplicates(t_list *node);
void	free_stacks(t_list **node_a, t_list **node_b);
// stack_init_utils_2.c
char	*ft_strchr(const char *str, int c);
int		ft_strlen(char *str);
int		process_split_argument(char *arg, t_list **node);
int		process_single_argument(char *arg, t_list **node);
t_list	*parse_numbers(int argc, char **argv);
// stack_init_utils_3.c
void	ft_free_split(char **matrix);
int		ft_count_words(char	*s, char c);
char	*copy_word(char *s, int start, int len);
char	**ft_words_dup(char **matrix, char *s, char c);
char	**ft_split(char	*s, char c);
// operations.c
void	sa(t_list **node_a, int flag);
void	sb(t_list **node_b, int flag);
void	ss(t_list **node_a, t_list **node_b);
void	pa(t_list **node_a, t_list **node_b);
void	pb(t_list **node_a, t_list **node_b);
// operations_1.c
void	ra(t_list **node_a, int flag);
void	rb(t_list **node_b, int flag);
void	rr(t_list **node_a, t_list **node_b);
// operations_2.c
void	rra(t_list **node_a, int flag);
void	rrb(t_list **node_b, int flag);
void	rrr(t_list **node_a, t_list **node_b);
// algorithms.c
void	sort_two(t_list **stack_a);
void	sort_three(t_list **stack_a);
void	push_swap(t_list **stack_a, t_list **stack_b);
// cost_algorithm.c
void	normalize_values(t_list **stack);
void	place_position(t_list *stack);
int		final_ta(t_list *stack_a, t_list *tmp_node, int target, int best_index);
int		get_target(t_list *stack_a, int index_b);
void	cal_costs(t_list *stack_a, t_list *stack_b, int size_a, int size_b);
int		absolute_value(int cost_a, int cost_b);
t_list	*get_cheapest_move(t_list *stack);
void	double_rotations(t_list **stack_a, t_list **stack_b, t_list *cheapest);
void	single_rotations(t_list **stack_a, t_list **stack_b, t_list *cheapest);
void	execute_cheapest(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack_a, int min_pos, int size);
void	final_rotate(t_list **stack_a);
void	cost_algorithm(t_list **stack_a, t_list **stack_b);

#endif