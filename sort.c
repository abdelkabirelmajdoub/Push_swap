/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:17:08 by ael-majd          #+#    #+#             */
/*   Updated: 2025/02/10 10:07:07 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

int	find_min(t_stack *a)
{
	int	min;

	min = a->value;
	while (a)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	min;

	min = find_min(*a);
	while (stack_size(*a) != 3)
	{
		if ((*a)->value == min)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	pa(a, b);
}

int	find_index(t_stack *stack, int value)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->value == value)
			return (index);
		stack = stack->next;
		index++;
	}
	return (-1);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min;
	int	i;

	i = 0;
	while (i < 2)
	{
		min = find_min(*a);
		while ((*a)->value != min)
		{
			if (find_index(*a, min) <= stack_size(*a) / 2)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
		i++;
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}
