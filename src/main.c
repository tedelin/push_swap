/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:49:51 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/09 18:05:02 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

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

void	build_stack(t_stack **stack, int nb, char **av)
{
	int	i;

	i = 1;
	while (i < nb)
		add_back(stack, ft_atoi(av[i++]));
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

int	main(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*b;
	int		i;

	stack = NULL;
	b = NULL;
	if (ac >= 2)
	{
		i = 1;
		while (i < ac)
		{
			if (!(check_arg_numb(av[i]))
				|| check_for_double(av, ac, i, av[i]))
				return (ft_putendl_fd("Error", 2), 0);
			i++;
		}
		build_stack(&stack, ac, av);
		main_sort(&stack, &b);
		free_stack(&stack);
		free_stack(&b);
	}
	else
		ft_putendl_fd("Error", 2);
}
