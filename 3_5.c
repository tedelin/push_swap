/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:11:58 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/04 19:07:57 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_elt(t_stack **stack)
{
	if (((*stack)->content < (*stack)->next->content && (*stack)->content < (*stack)->next->next->content) && (*stack)->next->content < (*stack)->next->next->content) // replace by check sort function
		return;
	else if ((*stack)->content > (*stack)->next->content && (*stack)->content > (*stack)->next->next->content && (*stack)->next->content > (*stack)->next->next->content) // 2
	{
		sa(stack);
		rra(stack);
	}
	else if ((*stack)->content < (*stack)->next->content && (*stack)->content < (*stack)->next->next->content) // 4
	{
		sa(stack);
		ra(stack);
	}
	else if ((*stack)->content > (*stack)->next->content && (*stack)->content > (*stack)->next->next->content) // 3
		ra(stack);
	else if ((*stack)->content > (*stack)->next->content) // 1
		sa(stack);
	else if ((*stack)->next->next->content < (*stack)->next->content) // 5
		rra(stack);
}

void	ft_five_elt(t_stack **a, t_stack **b)
{
	pb(a, b);
	pb(a, b);
	ft_three_elt(a);
}
