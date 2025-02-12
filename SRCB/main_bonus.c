/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:16:15 by ael-majd          #+#    #+#             */
/*   Updated: 2025/02/10 15:14:43 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	do_it(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3) && line[3] == '\0')
		sa(a);
	else if (!ft_strncmp(line, "sb\n", 3) && line[3] == '\0')
		sb(b);
	else if (!ft_strncmp(line, "ss\n", 3) && line[3] == '\0')
		ss(a, b);
	else if (!ft_strncmp(line, "pa\n", 3) && line[3] == '\0')
		pa(a, b);
	else if (!ft_strncmp(line, "pb\n", 3) && line[3] == '\0')
		pb(a, b);
	else if (!ft_strncmp(line, "ra\n", 3) && line[3] == '\0')
		ra(a);
	else if (!ft_strncmp(line, "rb\n", 3) && line[3] == '\0')
		rb(b);
	else if (!ft_strncmp(line, "rr\n", 3) && line[3] == '\0')
		rr(a, b);
	else if (!ft_strncmp(line, "rra\n", 4) && line[4] == '\0')
		rra(a);
	else if (!ft_strncmp(line, "rrb\n", 4) && line[4] == '\0')
		rrb(b);
	else if (!ft_strncmp(line, "rrr\n", 4) && line[4] == '\0')
		rrr(a, b);
	else
		return (1);
	return (0);
}

int	get_ins(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (do_it(a, b, line))
		{
			free(line);
			stack_error(a, b);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ac >= 2)
	{
		stack_init(&a, av);
		if (!get_ins(&a, &b))
			stack_error(&a, &b);
		else
		{
			if (is_sorted(a) && !b)
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
	}
	else
		return (1);
	return (free_stack(&a), free_stack(&b), 0);
}
