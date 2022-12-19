/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:58:18 by tedelin           #+#    #+#             */
/*   Updated: 2022/12/19 19:02:58 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

void	add_front(t_stack **stack, int content)
{
	t_stack	*elt;

	elt = malloc(sizeof(t_stack));
	if (!elt)
		return ;
	elt->content = content;
	elt->next = (*stack);
	(*stack) = elt;
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	add_front(a, (*b)->content);
	tmp = (*b);
	(*b) = (*b)->next;
	free(tmp);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	add_front(b, (*a)->content);
	tmp = (*a);
	(*a) = (*a)->next;
	free(tmp);
}
