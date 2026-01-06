/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:38:45 by omghazi           #+#    #+#             */
/*   Updated: 2024/04/05 12:19:17 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

/*------------Struct----------*/
typedef struct s_stack
{
	int					value;
	int					position;
	int					index;
	int					length;
	struct s_stack		*max;
	struct s_stack		*min;
	struct s_stack		*next;
}	t_stack;

/*------------Utils----------*/
void		error(void);
int			is_overflow(long n);
void		ft_putendl(char *s);
void		free_2d(char **new, int i);
bool		is_duplicate(t_stack **stack);
bool		is_valid(char *av);
void		ft_swap(int *x, int *y);
int			is_space(char c);

/*------------Libft----------*/
t_stack		*ft_lstnew(int value);
void		ft_lstadd_back(t_stack **stack, t_stack *node);
void		ft_lstclean(t_stack **stack);
void		ft_lstadd_front(t_stack **stack, t_stack *node);
char		**ft_split(char *s);
long		ft_atoi(char *s);
int			ft_lstsize(t_stack **stack);

/*------------Parse----------*/
void		fill_stack(t_stack **stack, char **av);

/*------------Algorithms----------*/
t_stack		*ft_lstlast(t_stack *stack);
t_stack		*min_node(t_stack **stack);
int			find_min(t_stack **stack);
bool		is_sorted(t_stack *stack);
void		max_node(t_stack *stack);
void		find_position(t_stack *stack);
void		sort_three(t_stack **stack);
void		sort_four(t_stack **stack_a, t_stack **stack_b);
void		sort_five(t_stack **stack_a, t_stack **stack_b);
void		index_stack(t_stack **stack);
void		heavy_sort(t_stack **stack_a, t_stack **stack_b);
void		push_to_a(t_stack **a, t_stack **b, int big);

/*------------Actions----------*/
int			pa(t_stack **stack_a, t_stack **stack_b);
int			pb(t_stack **stack_a, t_stack **stack_b);
int			ra(t_stack **stack);
int			rb(t_stack **stack);
int			rr(t_stack **stack_a, t_stack **stack_b);
int			rra(t_stack **stack);
int			rrb(t_stack **stack);
int			rrr(t_stack **stack_a, t_stack **stack_b);
int			pa(t_stack **stack_a, t_stack **stack_b);
int			pb(t_stack **stack_a, t_stack **stack_b);
int			sa(t_stack **stack_a);
int			sb(t_stack **stack_b);
int			ss(t_stack **stack_a, t_stack **stack_b);
