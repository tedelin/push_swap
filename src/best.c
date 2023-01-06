/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:07:25 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/06 18:39:01 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_a(t_stack **a, int elt)
{
	t_stack	*cur;

	cur = (*stack);
	if (cur->content > elt)
		return (0);


}

int	cost_first(t_stack **stack, int pos, int elt)
{
	int	i;
	int	size;

	i = 0;
	size = stack_size(stack);
	if (pos == 0)
		return (cost);
	if (pos > size / 2)
	{
		if (pos == size)
			return (1);
		else
			return (size - pos + 1); // add * -1 to handle reverse rotate movement
	}
	else
	{
		if (pos == 0)
			return (1);
		else
			return (pos + 1);
	}
}
