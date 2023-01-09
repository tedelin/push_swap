/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:07:25 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/09 18:36:04 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int	cost_a(t_stack **a, int elt)
{
	int	i;
	int	j;
	int	*tab;

	i = 0;
	j = stack_size(a) - 1;
	tab = build_tab(a);
	if (tab[j] < elt && elt < tab[0])
		return (0);
	while (i < stack_size(a) / 2)
	{
		if (tab[i] < elt && elt < tab[i + 1])
			return (free(tab), i + 1);
		i++;
	}
	while (j >= stack_size(a) / 2)
	{
		if (tab[j] > elt && elt > tab[j - 1])
			return (free(tab), (stack_size(a) - j) * (-1));
		j--;
	}
	return (free(tab), cost_max(a));
}

int	cost_b(t_stack **b, int elt)
{
	int		pos;
	int		size;
	t_stack	*cur;

	pos = 0;
	size = stack_size(b);
	cur = (*b);
	while (cur && cur->content != elt)
	{
		cur = cur->next;
		pos++;
	}
	if (pos < size / 2)
		return (pos + 1);
	return ((size - pos + 1) * (-1));
}

int	*best_to_push(t_stack **a, t_stack **b)
{
	int		*best;
	int		tmp[2];
	t_stack	*cur;

	best = malloc(sizeof(int) * 2);
	best[0] = cost_a(a, (*b)->content);
	best[1] = cost_b(b, (*b)->content);
	cur = (*b)->next;
	while (cur)
	{
		tmp[0] = cost_a(a, cur->content);
		tmp[1] = cost_b(b, cur->content);
		if (ft_abs(tmp[0]) + ft_abs(tmp[1]) < ft_abs(best[0]) + ft_abs(best[1]))
		{
			best[0] = tmp[0];
			best[1] = tmp[1];
		}
		cur = cur->next;
	}
	return (best);
}

/* void	smart_moves(t_stack **a, t_stack **b, int *tab) */
/* { */
/* 	if (tab[0] * tab[1] > 0) */
/* 	{ */
/* 	} */
/* } */

void	best_exec(t_stack **a, t_stack **b, int *tab)
{
	while (tab[0] > 0)
	{
		ra(a, 1);
		tab[0] = tab[0] - 1;
	}
	while (tab[0] < 0)
	{
		rra(a, 1);
		tab[0] = tab[0] + 1;
	}
	while (tab[1] > 1)
	{
		rb(b, 1);
		tab[1] = tab[1] - 1;
	}
	while (tab[1] < -1)
	{
		rrb(b, 1);
		tab[1] = tab[1] + 1;
	}
	pa(a, b);
}
