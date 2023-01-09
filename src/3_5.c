/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:11:58 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/09 18:37:15 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//first condition to replace with sort function

void	ft_three_elt(t_stack **stack)
{
	t_stack	*cur;

	cur = (*stack);
	if ((cur->content < cur->next->content
			&& cur->content < cur->next->next->content)
		&& cur->next->content < cur->next->next->content)
		return ;
	else if (cur->content > cur->next->content
		&& cur->content > cur->next->next->content
		&& cur->next->content > cur->next->next->content)
	{
		sa(stack);
		rra(stack, 1);
	}
	else if (cur->content < cur->next->content
		&& cur->content < cur->next->next->content)
	{
		sa(stack);
		ra(stack, 1);
	}
	else if (cur->content > cur->next->content
		&& cur->content > cur->next->next->content)
		ra(stack, 1);
	else if (cur->content > cur->next->content)
		sa(stack);
	else if (cur->next->next->content < cur->next->content)
		rra(stack, 1);
}

void	ft_five_elt(t_stack **a, t_stack **b)
{
	pb(a, b);
	pb(a, b);
	ft_three_elt(a);
}
