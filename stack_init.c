/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:29:35 by ael-majd          #+#    #+#             */
/*   Updated: 2025/02/09 17:45:49 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_back(t_stack **stack, int value)
{
	t_stack	*tmp;
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		error();
	new->value = value;
	new->next = NULL;
	if (*stack)
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*stack = new;
}

int	stack_size(t_stack *stack)
{
	int	size;

	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	is_number(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] && (s[i] == '-' || s[i] == '+'))
			i++;
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_dup(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}
