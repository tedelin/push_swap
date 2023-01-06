/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:30:08 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/06 16:54:22 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

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

void	check_top(t_stack **stack, int lis_len, int min_val)
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
	if (i_min <= lis_len / 2)
	{
		while ((*stack)->content != min_val)
			ra(stack);
	}
	else if (i_min > lis_len / 2)
	{
		while ((*stack)->content != min_val)
			rra(stack);
	}
}

void	first_sort(t_stack **a, t_stack **b)
{
	int	*tab;
	int	len;
	int	*tab_lis;
	int	*lis;
	int	lis_max;

	tab = build_tab(a);
	len = stack_size(a);
	tab_lis = lis_tab(tab, len);
	lis = build_lis(tab, tab_lis, len);
	lis_max = get_lis_max(tab_lis, len, 1);
	while ((*a))
	{
		if (check_full_lis(a, lis, lis_max) == 1)
			break ;
		else if (check_lis(lis, lis_max, (*a)->content) == 0)
			pb(a, b);
		else
			ra(a);
	}
	check_top(a, lis_max, lis[0]);
	free(tab);
	free(tab_lis);
	free(lis);
}
