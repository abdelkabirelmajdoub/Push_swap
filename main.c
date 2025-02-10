/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:56:41 by ael-majd          #+#    #+#             */
/*   Updated: 2025/02/09 18:22:02 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_empty(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j] == ' ' || av[i][j] == '\t')
			j++;
		if (!av[i][j])
			error();
		i++;
	}
	return (1);
}

void	stack_init(t_stack **a, char **av)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (av[i] && check_empty(av))
	{
		split = ft_split(av[i], ' ');
		j = 0;
		while (split[j])
		{
			if (!is_number(split[j]))
				check_error(split, a);
			if (ft_atoi(split[j]) > INT_MAX || ft_atoi(split[j]) < INT_MIN)
				check_error(split, a);
			if (split[j][0] == '-' || split[j][0] == '+')
				if (!split[j][1])
					check_error(split, a);
			stack_add_back(a, ft_atoi(split[j++]));
		}
		free_args(split);
		i++;
	}
	if (!check_dup(*a))
		stack_error(a, NULL);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (!av[1] || (ac == 2 && !av[1][0]))
		return (1);
	if (ac >= 2)
	{
		stack_init(&a, av);
		if (is_sorted(a))
			return (free_stack(&a), 0);
		sort(&a, &b);
	}
	else
		return (1);
	free_stack(&a);
	free_stack(&b); 
	return (0);
}
