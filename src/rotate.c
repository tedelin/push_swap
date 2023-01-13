/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:20:09 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/13 16:51:42 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ra(t_stack **a, int display)
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
	if (display == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int display)
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
	if (display == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}
