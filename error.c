/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:36:28 by ael-majd          #+#    #+#             */
/*   Updated: 2025/02/09 17:41:02 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "error\n", 6);
	exit(1);
}

void	free_args(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	stack_error(t_stack **a, t_stack **b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	error();
}

void	check_error(char **split, t_stack **a)
{
	free_args(split);
	free_stack(a);
	error();
}
