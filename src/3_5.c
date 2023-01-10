/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:11:58 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/10 18:07:03 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack)
{
	int	*tab;
	int	i;

	tab = build_tab(stack);
	i = 0;
	while (i < stack_size(stack) - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
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

	if (is_sorted(a))
		return ;
	pb(a, b);
	pb(a, b);
	ft_three_sort(a);
	best_exec(a, b, best_to_push(a, b));
	pa(a, b);
	best_exec(a, b, best_to_push(a, b));
	pa(a, b);
	final_sort(a, stack_size(a), get_min_stack(a));
}
