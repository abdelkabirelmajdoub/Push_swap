/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:58:50 by ael-majd          #+#    #+#             */
/*   Updated: 2025/02/10 15:13:17 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define BUFFER_SIZE 42
// libft
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	**ft_split(char const *s, char c);
long	ft_atoi(char *str);
char	*ft_substr(char const *s, int start, int len);
//stack

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	stack_add_back(t_stack **stack, int value);
int		stack_size(t_stack *stack);
int		is_number(char *s);
int		check_dup(t_stack *a);
// stack init
void	stack_init(t_stack **a, char **av);
int		is_sorted(t_stack *a);
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
// error handler

void	error(void);
void	free_args(char **s);
void	free_stack(t_stack **stack);
void	stack_error(t_stack **a, t_stack **b);
void	check_error(char **split, t_stack **a);

#endif