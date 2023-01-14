/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:11:58 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/14 18:08:09 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	is_sorted(t_stack **stack)
{
	int	*tab;
	int	i;

	tab = build_tab(stack);
	i = 0;
	while (tab != NULL && i < stack_size(stack) - 1)
	{
		if (tab[i] > tab[i + 1])
			return (free(tab), 0);
		i++;
	}
	return (free(tab), 1);
}

void	ft_three_sort(t_stack **stack)
{
	t_stack	*cur;

	cur = (*stack);
	if (is_sorted(stack))
		return ;
	else if (cur->content > cur->next->content
		&& cur->content > cur->next->next->content
		&& cur->next->content > cur->next->next->content)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (cur->content < cur->next->content
		&& cur->content < cur->next->next->content)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (cur->content > cur->next->content
		&& cur->content > cur->next->next->content)
		ra(stack, 1);
	else if (cur->content > cur->next->content)
		sa(stack, 1);
	else if (cur->next->next->content < cur->next->content)
		rra(stack, 1);
}

void	ft_five_sort(t_stack **a, t_stack **b)
{
	int	*best_move;

	if (is_sorted(a))
		return ;
	pb(a, b);
	pb(a, b);
	ft_three_sort(a);
	while (stack_size(b) != 0)
	{
		best_move = best_to_push(a, b);
		if (!best_move)
			return ;
		best_exec(a, b, best_move);
		pa(a, b);
		free(best_move);
	}
	final_sort(a, stack_size(a), get_min_stack(a));
}
