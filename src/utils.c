/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:45:18 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/09 18:00:54 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	*build_tab(t_stack **stack)
{
	int		*tab;
	t_stack	*cur;
	int		i;

	tab = malloc(sizeof(int) * stack_size(stack));
	if (!tab)
		return (NULL);
	cur = (*stack);
	i = 0;
	while (cur)
	{
		tab[i++] = cur->content;
		cur = cur->next;
	}
	return (tab);
}

int	get_min_stack(t_stack **stack)
{
	int		min;
	t_stack	*cur;

	cur = (*stack);
	min = cur->content;
	while (cur)
	{
		if (cur->content < min)
			min = cur->content;
		cur = cur->next;
	}
	return (min);
}

int	cost_max(t_stack **stack)
{
	int		max;
	int		i;
	int		pos;
	t_stack	*cur;

	cur = (*stack);
	max = cur->content;
	i = 0;
	pos = 0;
	while (cur)
	{
		if (cur->content > max)
		{
			max = cur->content;
			pos = i;
		}
		cur = cur->next;
		i++;
	}
	if (pos < stack_size(stack))
		return (pos + 1);
	return ((stack_size(stack) - pos) * (-1));
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (nb * (-1));
	return (nb);
}
