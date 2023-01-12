/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:51:58 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/12 17:04:15 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"
#include <stddef.h>

int	check_arg_numb(char *s)
{
	int	i;

	i = 0;
	if (s && (s[0] == '-' || s[0] == '+'))
		i++;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_for_double(char **av, int nb, int current, char *s)
{
	int		i;
	size_t	j;

	i = 1;
	while (i < nb)
	{
		if (i == current)
			i++;
		else
		{
			j = 0;
			while (av[i][j] && s[j])
			{
				if (av[i][j] != s[j])
					break ;
				j++;
			}
			if (j == ft_strlen(av[i]) && ft_strlen(s) == j)
				return (1);
			i++;
		}
	}
	return (0);
}

void	sort_choose(t_stack **a, t_stack **b, int ac, char **av)
{
	int	size;

	build_stack(a, ac, av);
	size = stack_size(a);
	if (size == 5)
		ft_five_sort(a, b);
	else if (size == 3)
		ft_three_sort(a);
	else if (size == 2 && (*a)->content > (*a)->next->content)
		ra(a, 1);
	else
		main_sort(a, b);
	free_stack(a);
	free_stack(b);
}
