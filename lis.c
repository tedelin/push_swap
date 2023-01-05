/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:33:22 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/05 19:12:45 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int	*init_lis(int *tab, int len)
{
	int	i;
	int	*lis_tab;

	lis_tab = (int *)malloc(sizeof(int) * len);
	if (!lis_tab)
		return (NULL);
	i = 0;
	while (i < len)
		lis_tab[i++] = 1;
	return (lis_tab);
}

int	*lis_tab(int *tab, int len)
{
	int	i;
	int	j;
	int	*lis_tab;

	lis_tab = init_lis(tab, len);
	i = 1;
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (tab[i] > tab[j] && lis_tab[i] < lis_tab[j] + 1)
				lis_tab[i] = lis_tab[j] + 1;
			j++;
		}
		i++;
	}
	return (lis_tab);
}

int	get_lis_max(int *tab, int len, int choice)
{
	int	i;
	int	max;
	int	ind;

	i = 0;
	max = tab[0];
	ind = 0;
	while (i < len)
	{
		if (tab[i] > max)
		{
			max = tab[i];
			ind = i;
		}
		i++;
	}
	if (choice == 0)
		return (ind);
	else if (choice == 1)
		return (max);
}

int	*build_lis(int *tab, int *lis_tab, int len)
{
	int	i_max;
	int	lis_max;
	int	i;
	int	*lis;

	i_max = get_lis_max(lis_tab, len, 0);
	lis_max = get_lis_max(lis_tab, len, 1);
	lis = (int *)malloc(sizeof(int) * lis_max);
	lis[lis_max - 1] = tab[i_max];
	lis_max--;
	i = i_max - 1;
	while (i >= 0)
	{
		if (tab[i_max] > tab[i] && lis_tab[i] == lis_max)
		{
			lis[lis_max - 1] = tab[i];
			lis_max--;
		}
		i--;
	}
	return (lis);
}

int	check_lis(int *lis, int len, int elt)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (lis[i] == elt)
			return (1);
		i++;
	}
	return (0);
}

int	check_full_lis(t_stack **stack, int *lis, int len)
{
	t_stack	*tmp;

	tmp = (*stack);
	while (tmp)
	{
		if (check_lis(lis, len, tmp->content) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/* int	main(void) */
/* { */
/* 	/1* int	tab[8] = {10, 22, 9, 33, 21, 50, 41, 60}; *1/ */
/* 	/1* int	tab[10] = {0, 4, 6, 1, 2, 10, 7, 3, 8, 9}; *1/ */
/* 	/1* int	tab[7] = {3, 4, -1, 0, 6, 2, 3}; *1/ */
/* 	int	tab[16] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}; */
/* 	int *lis = build_lis(tab, lis_tab(tab, 16), 16); */
/* 	/1* int max = lis_max(tab, 8); *1/ */

/* 	int	i = 0; */
/* 	while (i < 6) */
/* 		printf("%d, ", lis[i++]); */
/* } */
