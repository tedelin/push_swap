/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:30:23 by tedelin           #+#    #+#             */
/*   Updated: 2022/12/16 17:32:39 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_stack
{
	int	content;
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

/* t_stack *last_stack(t_stack *a); */
/* t_stack	*add_stack(t_stack *a, int content); */
/* int	stack_size(t_stack *a); */
/* void	print_stack(t_stack *s); */

#endif
