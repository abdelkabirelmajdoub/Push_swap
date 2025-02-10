/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:12:50 by ael-majd          #+#    #+#             */
/*   Updated: 2025/02/10 13:20:01 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ra(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	rb(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	ra(b);
}

void	rra(t_stack **stack)
{
	t_stack	*last;
	t_stack	*s_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	s_last = *stack;
	while (s_last->next && s_last->next->next)
		s_last = s_last->next;
	last = s_last->next;
	s_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrb(t_stack **stack)
{
	t_stack	*will_first;
	t_stack	*s_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	s_last = *stack;
	while (s_last->next && s_last->next->next)
		s_last = s_last->next;
	will_first = s_last->next;
	s_last->next = NULL;
	will_first->next = *stack;
	*stack = will_first;
}
