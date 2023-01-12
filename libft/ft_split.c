/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:09:42 by tedelin           #+#    #+#             */
/*   Updated: 2022/12/12 15:42:50 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count(const char *str, char c)
{
	int	words;

	words = 0;
	while (*str)
	{
		if (*str != c)
		{
			words++;
			while (*str != c && *str)
				str++;
		}
		else
			str++;
	}
	return (words);
}

static	char	*ft_wordadd(const char *s, char c)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	i = 0;
	while (s[len] != c && s[len])
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (word)
	{
		while (s[i] && i < len)
		{
			word[i] = s[i];
			i++;
		}
		word[i] = '\0';
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	int			j;
	char		**tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[j] = ft_wordadd(&s[i], c);
			if (!tab[j])
				return (free(tab), NULL);
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	tab[j] = 0;
	return (tab);
}
