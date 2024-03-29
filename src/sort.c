/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:30:08 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/16 14:56:20 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	check_lis(int *lis, int len, int elt)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (lis[i] == elt)
			return (1);
		i++;
	}
	return (0);
}

int	check_full_lis(t_stack **stack, int *lis, int len)
{
	t_stack	*tmp;

	tmp = (*stack);
	while (tmp)
	{
		if (check_lis(lis, len, tmp->content) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	final_sort(t_stack **stack, int size, int min_val)
{
	t_stack	*cur;
	int		i_min;

	if ((*stack)->content == min_val)
		return ;
	cur = (*stack);
	i_min = 0;
	while (cur && cur->content != min_val)
	{
		cur = cur->next;
		i_min++;
	}
	if (i_min <= size / 2)
	{
		while ((*stack)->content != min_val)
			ra(stack, 1);
	}
	else if (i_min > size / 2)
	{
		while ((*stack)->content != min_val)
			rra(stack, 1);
	}
}

int	first_sort(t_stack **a, t_stack **b)
{
	int	*tab;
	int	len;
	int	*tab_lis;
	int	*lis;
	int	lis_max;

	tab = build_tab(a);
	if (!tab)
		return (0);
	len = stack_size(a);
	tab_lis = lis_tab(tab, len);
	if (!tab_lis)
		return (0);
	lis = build_lis(tab, tab_lis, len);
	if (!lis)
		return (0);
	lis_max = get_lis_max(tab_lis, len, 1);
	while (check_full_lis(a, lis, lis_max) == 0)
	{
		if (check_lis(lis, lis_max, (*a)->content) == 0)
			pb(a, b);
		else
			ra(a, 1);
	}
	return (free(tab), free(tab_lis), free(lis), 1);
}

void	main_sort(t_stack **a, t_stack **b)
{
	int	*best_move;

	first_sort(a, b);
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
