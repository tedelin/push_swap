/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:58:18 by tedelin           #+#    #+#             */
/*   Updated: 2022/12/19 17:30:08 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void	print_stack(t_stack **a)
{
	while ((*a))
	{
		printf("%d\n", (*a)->content);
		(*a) = (*a)->next;
	}
}

void	add_front(t_stack **stack, int content)
{
	t_stack	*elt;

	elt = malloc(sizeof(t_stack));
	if (!elt)
		return ;
	elt->content = content;
	elt->next = (*stack);
	stack = &elt;
}


void	pa(t_stack **a, t_stack **b)
{
	if (!(*b))
		return ;
	add_front(a, (*b)->content);
}





/* void	pb(t_stack **a, t_stack **b) */
/* { */
/* } */




int main(void)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	a->content = 1;
	/* a->next = malloc(sizeof(t_stack));; */
	/* a->next->content = 2; */
	/* a->next->next = NULL; */
	add_front(&a, 2);
	add_front(&a, 3);
	print_stack(&a);
}
