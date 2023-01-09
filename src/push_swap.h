/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:30:23 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/09 16:07:21 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}		t_stack;

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* Utils functions */
void	add_front(t_stack **stack, int content);
void	add_back(t_stack **stack, int content);
int		stack_size(t_stack **stack);
int		*build_tab(t_stack **stack);
int		get_min_stack(t_stack **stack);
int		ft_abs(int nb);

/* Sorts functions */
void	ft_three_elt(t_stack **stack);
void	ft_five_elt(t_stack **a, t_stack **b);
void	first_sort(t_stack **a, t_stack **b);
void	main_sort(t_stack **a, t_stack **b);

int		cost_a(t_stack **a, int elt);
int		cost_b(t_stack **a, int elt);
int		cost_max(t_stack **stack);
int		*best_to_push(t_stack **a, t_stack **b);
void	best_exec(t_stack **a, t_stack **b, int *tab);
void	final_sort(t_stack **stack, int size, int min_val);

/* Lis functions */
int		*init_lis(int len);
int		*lis_tab(int *tab, int len);
int		get_lis_max(int *tab, int len, int choice);
int		*build_lis(int *tab, int *lis_tab, int len);
int		check_lis(int *lis, int len, int elt);
int		check_full_lis(t_stack **stack, int *lis, int len);

/* Testing functions remove later */
void	print_stack(t_stack **a);
void	free_stack(t_stack **stack);

#endif
