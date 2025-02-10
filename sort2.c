/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:06:09 by ael-majd          #+#    #+#             */
/*   Updated: 2025/02/09 17:31:30 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		i;

	tmp = *a;
	while (tmp)
	{
		tmp2 = *a;
		i = 0;
		while (tmp2)
		{
			if (tmp->value > tmp2->value)
				i++;
			tmp2 = tmp2->next;
		}
		tmp->index = i;
		tmp = tmp->next;
	}
}

void	ft_range(t_stack **a, t_stack **b)
{
	int	min_range;
	int	max_range;

	min_range = 0;
	max_range = 0.045 * stack_size(*a) + 10;
	while (*a)
	{
		if ((*a)->index > max_range)
			ra(a);
		else
		{
			pb(a, b);
			if ((*b)->index < min_range)
				rb(b);
			min_range++;
			max_range++;
		}
	}
}

static int	max_v(t_stack *stack)
{
	int	i;
	int	index;

	i = 0;
	index = stack_size(stack) - 1;
	while (stack)
	{
		if (stack->index == index)
			return (i);
		i++;
		stack = stack->next;
	}
	return (index);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	size;
	int	index;

	size = stack_size(*a);
	set_index(a);
	ft_range(a, b);
	while (*b)
	{
		size = stack_size(*b);
		index = max_v(*b);
		if (index == 0)
			pa(a, b);
		else if (index > (size / 2) && index != 0)
			rrb(b);
		else if (index <= (size / 2) && index != 0)
			rb(b);
	}
	free_stack(a);
	free_stack(b);
}

void	sort(t_stack **a, t_stack **b)
{
	if (stack_size(*a) == 2)
		sort_two(a);
	else if (stack_size(*a) == 3)
		sort_three(a);
	else if (stack_size(*a) == 4)
		sort_four(a, b);
	else if (stack_size(*a) == 5)
		sort_five(a, b);
	else
		sort_stacks(a, b);
}
