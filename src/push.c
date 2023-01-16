/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:58:18 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/16 15:28:48 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if (!*b)
		return ;
	tmp_a = (*a);
	tmp_b = (*b)->next;
	(*a) = (*b);
	(*a)->next = tmp_a;
	(*b) = tmp_b;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if (!*a)
		return ;
	tmp_b = (*b);
	tmp_a = (*a)->next;
	(*b) = (*a);
	(*b)->next = tmp_b;
	(*a) = tmp_a;
	write(1, "pb\n", 3);
}
