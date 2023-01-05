/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:51:12 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/05 19:19:57 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	print_stack(t_stack **a)
{
	t_stack	*current;

	current = (*a);
	while (current)
	{
		printf("%d\n", current->content);
		current = current->next;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while ((*stack))
	{
		tmp = (*stack);
		(*stack) = (*stack)->next;
		free(tmp);
	}
}

int main(void)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;

	a = NULL;
	b = NULL;
	c = NULL;
	/* a = malloc(sizeof(t_stack)); */
	/* a->content = 1; */
	b = a;
	add_front(&a, 2);
	add_front(&a, 3);
	add_front(&a, 6);

	/* b = malloc(sizeof(t_stack)); */
	/* b->content = 42; */
	add_front(&b, -42);

	printf("stack a\n");
	print_stack(&a);
	printf("stack b \n");
	print_stack(&b);

	/* pa(&a, &b); */
	/* pa(&a, &b); */
	/* sa(&a); */
	rrb(&a);

	printf("stack a\n");
	print_stack(&a);
	printf("stack b\n");
	print_stack(&b);

	free_stack(&a);
	free_stack(&b);
}
