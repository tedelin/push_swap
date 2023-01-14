/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:58:18 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/14 18:25:47 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	if (add_front(a, (*b)->content))
	{
		tmp = (*b);
		(*b) = (*b)->next;
		free(tmp);
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	if (add_front(b, (*a)->content))
	{
		tmp = (*a);
		(*a) = (*a)->next;
		free(tmp);
		write(1, "pb\n", 3);
	}
}
