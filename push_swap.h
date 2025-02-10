/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:57:08 by ael-majd          #+#    #+#             */
/*   Updated: 2025/02/09 17:32:44 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

// moves
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **a, t_stack **b);
// algorithms 
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	sort_stacks(t_stack **a, t_stack **b);
void	sort(t_stack **a, t_stack **b);
// stack init

void	stack_add_back(t_stack **stack, int value);
int		stack_size(t_stack *stack);

// libft

long	ft_atoi(char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, int start, int len);

// error handler

void	error(void);
void	free_args(char **s);
int		check_dup(t_stack *a);
void	stack_error(t_stack **a, t_stack **b);
void	free_stack(t_stack **stack);
int		is_sorted(t_stack *a);
void	check_error(char **split, t_stack **a);
int		is_number(char *s);
#endif