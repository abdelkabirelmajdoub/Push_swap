/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:12:50 by ael-majd          #+#    #+#             */
/*   Updated: 2025/02/09 17:00:17 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	ra(b);
	write(1, "rr\n", 3);
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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
}
