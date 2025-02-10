/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:38:47 by ael-majd          #+#    #+#             */
/*   Updated: 2025/02/09 16:58:34 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		in_word = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			if (in_word == 0)
			{
				count++;
				in_word = 1;
			}
			i++;
		}
	}
	return (count);
}

static char	**free_split(char **s, int j)
{
	while (j >= 0)
	{
		free(s[j]);
		j--;
	}
	free(s);
	return (NULL);
}

static char	**split_word(char **split, const char *s, char c)
{
	int	start;
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			split[j] = ft_substr(s, start, i - start);
			if (!split[j])
				return (free_split(split, j));
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**split;

	if (!s)
		return (NULL);
	count = count_word(s, c) + 1;
	split = malloc(sizeof(char *) * (count));
	if (!split)
		return (NULL);
	split = split_word(split, s, c);
	return (split);
}

int	is_sorted(t_stack *a)
{
	if (!a || !a->next)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
