/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:30:08 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/05 20:07:42 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	*build_tab(t_stack **stack)
{
	int	*tab;
	t_stack	*cur;
	int	i;

	tab = malloc(sizeof(int) * stack_size(stack));
	if (!tab)
		return (NULL);
	cur = (*stack);
	i = 0;
	while (cur)
	{
		tab[i++] = cur->content;
		cur = cur->next;
	}
	return (tab);
}

void	first_sort(t_stack **a, t_stack **b)
{
	int	*lis;
	int	*tab;
	int	len;
	int	lis_max;

	tab = build_tab(a);
	len = stack_size(a);
	lis = build_lis(tab, lis_tab(tab, len), len);
	lis_max = get_lis_max(tab, len, 1);
	while ((*a))
	{
		if (check_full_lis(a, lis, lis_max) == 1)
			break;
		else if (check_lis(lis, lis_max, (*a)->content) == 0)
			pb(a, b);
		else
			ra(a);
	}
}
