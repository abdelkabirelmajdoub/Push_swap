/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:46:57 by ael-majd          #+#    #+#             */
/*   Updated: 2025/02/09 17:47:47 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max(t_stack *a)
{
	int	max;

	max = a->value;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
	}
	return (max);
}

void	sort_three(t_stack **a)
{
	int	max;

	max = find_max(*a);
	if (max == (*a)->value)
		ra(a);
	else if ((*a)->next->value == max)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
