/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:30:23 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/06 17:16:20 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*previous;
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

/* Sorts functions */
void	ft_three_elt(t_stack **stack);
void	ft_five_elt(t_stack **a, t_stack **b);
void	first_sort(t_stack **a, t_stack **b);
int		*build_tab(t_stack **stack);

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
