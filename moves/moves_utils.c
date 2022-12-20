/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:14:23 by tedelin           #+#    #+#             */
/*   Updated: 2022/12/20 16:00:25 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

int	stack_size(t_stack **stack)
{
	int	size;
	t_stack	*current;

	if (!(*stack))
		return (0);
	size = 0;
	current = (*stack);
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	add_front(t_stack **stack, int content)
{
	t_stack	*elt;

	if (!(*stack))
	{
		stack = malloc(sizeof(t_stack));
		if (!(*stack))
			return;
		(*stack)->content = content;
		(*stack)->next = NULL;
		return ;
	}
	elt = malloc(sizeof(t_stack));
	if (!elt)
		return ;
	elt->content = content;
	elt->next = (*stack);
	(*stack) = elt;
}
