/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:14:23 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/14 18:44:43 by tedelin          ###   ########.fr       */
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

int	add_front(t_stack **stack, int content)
{
	t_stack	*elt;

	if (!(*stack))
	{
		elt = malloc(sizeof(t_stack));
		if (!elt)
		{
			free_stack(stack);
			return (0);
		}
		elt->content = content;
		elt->next = NULL;
		(*stack) = elt;
		return (1);
	}
	elt = malloc(sizeof(t_stack));
	if (!elt)
	{
		free_stack(stack);
		return (0);
	}
	elt->content = content;
	elt->next = (*stack);
	(*stack) = elt;
	return (1);
}

int	add_back(t_stack **stack, int content)
{
	t_stack	*elt;
	t_stack	*last;

	if (!(*stack))
	{
		elt = malloc(sizeof(t_stack));
		if (!elt)
			return (free_stack(stack), 0);
		elt->content = content;
		elt->next = NULL;
		(*stack) = elt;
		return (1);
	}
	elt = malloc(sizeof(t_stack));
	if (!elt)
		return (free_stack(stack), 0);
	elt->content = content;
	elt->next = NULL;
	last = (*stack);
	while (last && last->next)
		last = last->next;
	last->next = elt;
	return (1);
}

int	build_stack(t_stack **stack, int nb, char **av)
{
	int	i;

	i = 1;
	while (i < nb)
	{
		if (add_back(stack, ft_atoi(av[i])) == 0)
			return (0);
		i++;
	}
	return (1);
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
