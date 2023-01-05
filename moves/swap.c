/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:06:56 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/04 17:41:39 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **a)
{
	int	tmp;

	if (stack_size(a) < 2)
		return ;
	tmp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
	write (1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	int	tmp;

	if (stack_size(b) < 2)
		return ;
	tmp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = tmp;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
