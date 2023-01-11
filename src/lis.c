/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:33:22 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/11 19:21:49 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int	*init_lis(int len)
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

	lis_tab = init_lis(len);
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
