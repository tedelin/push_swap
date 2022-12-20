/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:20:09 by tedelin           #+#    #+#             */
/*   Updated: 2022/12/20 16:01:08 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*current;
	int	tmp;
	int	tmp2;

	current = (*a);
	tmp = current->content;
	while (current->next)
	{
		current->content = current->next->content;
		current = current->next;
		current->content = tmp;
		tmp = current->content;
	}
}

void	rb(t_stack **b)
{
	t_stack	*current;
	int	tmp;
	int	tmp2;

	current = (*b);
	tmp = current->content;
	while (current->next)
	{
		current->content = current->next->content;
		current = current->next;
		current->content = tmp;
		tmp = current->content;
	}
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
