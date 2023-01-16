/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:20:09 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/16 17:27:29 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ra(t_stack **a, int display)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	last = (*a);
	while (last->next)
		last = last->next;
	tmp->next = NULL;
	last->next = tmp;
	if (display == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int display)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	last = (*b);
	while (last && last->next)
		last = last->next;
	tmp->next = NULL;
	last->next = tmp;
	if (display == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}
