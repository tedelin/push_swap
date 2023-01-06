/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:20:09 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/06 16:54:22 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*current;
	int		tmp;

	current = (*a);
	tmp = current->content;
	while (current->next)
	{
		current->content = current->next->content;
		current = current->next;
		current->content = tmp;
		tmp = current->content;
	}
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*current;
	int		tmp;

	current = (*b);
	tmp = current->content;
	while (current->next)
	{
		current->content = current->next->content;
		current = current->next;
		current->content = tmp;
		tmp = current->content;
	}
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
