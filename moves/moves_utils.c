/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:14:23 by tedelin           #+#    #+#             */
/*   Updated: 2022/12/19 19:41:43 by tedelin          ###   ########.fr       */
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
	return (free(current), size);
}

void	add_front(t_stack **stack, int content)
{
	t_stack	*elt;

	elt = malloc(sizeof(t_stack));
	if (!elt)
		return ;
	elt->content = content;
	elt->next = (*stack);
	(*stack) = elt;
	/* free(elt); */
}
