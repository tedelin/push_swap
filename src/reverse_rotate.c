/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:55:20 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/16 14:48:27 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	rra(t_stack **a, int display)
{
	t_stack	*tmp_offset;
	t_stack	*tmp_begin;

	if (!*a || !(*a)->next)
		return ;
	tmp_offset = *a;
	tmp_begin = *a;
	while (tmp_offset->next != NULL)
		tmp_offset = tmp_offset->next;
	*a = tmp_offset;
	(*a)->next = tmp_begin;
	while (tmp_begin->next != *a)
		tmp_begin = tmp_begin->next;
	tmp_begin->next = NULL;
	if (display == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int display)
{
	t_stack	*tmp_offset;
	t_stack	*tmp_begin;

	if (!*b || !(*b)->next)
		return ;
	tmp_offset = *b;
	tmp_begin = *b;
	while (tmp_offset->next != NULL)
	tmp_offset = tmp_offset->next;
	*b = tmp_offset;
	(*b)->next = tmp_begin;
	while (tmp_begin->next != *b)
		tmp_begin = tmp_begin->next;
	tmp_begin->next = NULL;
	if (display == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
