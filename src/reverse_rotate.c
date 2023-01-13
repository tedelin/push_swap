/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:55:20 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/13 16:51:29 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	rra(t_stack **a, int display)
{
	t_stack	*last;
	t_stack	*next_last;

	if (stack_size(a) >= 2)
	{
		last = (*a);
		next_last = (*a);
		while (last && last->next)
			last = last->next;
		add_front(a, last->content);
		while (next_last && next_last->next && next_last->next->next)
			next_last = next_last->next;
		next_last->next = NULL;
		free(last);
	}
	if (display == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int display)
{
	t_stack	*last;
	t_stack	*next_last;

	if (stack_size(b) >= 2)
	{
		last = (*b);
		next_last = (*b);
		while (last && last->next)
			last = last->next;
		add_front(b, last->content);
		while (next_last && next_last->next && next_last->next->next)
			next_last = next_last->next;
		next_last->next = NULL;
		free(last);
	}
	if (display == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
