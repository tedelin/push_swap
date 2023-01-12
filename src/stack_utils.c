/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:14:23 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/12 16:59:44 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"
#include <stdlib.h>

int	stack_size(t_stack **stack)
{
	int		size;
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
		elt = malloc(sizeof(t_stack));
		if (!elt)
			return ;
		elt->content = content;
		elt->next = NULL;
		(*stack) = elt;
		return ;
	}
	elt = malloc(sizeof(t_stack));
	if (!elt)
		return ;
	elt->content = content;
	elt->next = (*stack);
	(*stack) = elt;
}

void	add_back(t_stack **stack, int content)
{
	t_stack	*elt;
	t_stack	*last;

	if (!(*stack))
	{
		elt = malloc(sizeof(t_stack));
		if (!elt)
			return ;
		elt->content = content;
		elt->next = NULL;
		(*stack) = elt;
		return ;
	}
	elt = malloc(sizeof(t_stack));
	if (!elt)
		return ;
	elt->content = content;
	elt->next = NULL;
	last = (*stack);
	while (last && last->next)
		last = last->next;
	last->next = elt;
}

void	build_stack(t_stack **stack, int nb, char **av)
{
	int	i;

	i = 1;
	while (i < nb)
		add_back(stack, ft_atoi(av[i++]));
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while ((*stack))
	{
		tmp = (*stack);
		(*stack) = (*stack)->next;
		free(tmp);
	}
}
