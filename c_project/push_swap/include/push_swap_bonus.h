/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:14:49 by omghazi           #+#    #+#             */
/*   Updated: 2024/04/14 15:28:15 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "get_next_line.h"

typedef struct s_stack
{
	int					value;
	void				*action;
	int					position;
	int					index;
	int					length;
	struct s_stack		*max;
	struct s_stack		*min;
	struct s_stack		*next;
}	t_stack;

/*-------------------Actions----------------*/
int			pa(t_stack **stack_a, t_stack **stack_b);
int			pb(t_stack **stack_a, t_stack **stack_b);
int			rra(t_stack **stack);
int			rrb(t_stack **stack);
int			rrr(t_stack **stack_a, t_stack **stack_b);
int			sa(t_stack **stack_a);
int			ss(t_stack **stack_a, t_stack **stack_b);
int			sb(t_stack **stack_b);
int			rb(t_stack **stack);
int			ra(t_stack **stack);
int			rr(t_stack **stack_a, t_stack **stack_b);

/*-------------------Utils----------------*/
void		fill_stack(t_stack **stack, char **av);
void		mr_propre(t_stack **a, t_stack **b, t_stack **action, int flag);
bool		is_empty(char **av);
bool		is_sorted(t_stack *stack);

/*-------------------Utils----------------*/
void		error(void);
int			is_overflow(long n);
void		free_2d(char **new, int i);
void		ft_swap(int *x, int *y);
int			is_space(char c);
void		ft_putendl(char *s);
int			check_value(char c);
bool		is_valid(char *av);
bool		is_duplicate(t_stack **stack);

/*-------------------Libft----------------*/
char		**ft_split(char *s);
int			ft_strcmp(char *s1, char *s2);
t_stack		*ft_lstnew(int val);
t_stack		*ft_lstnew_action(char *val);
void		ft_lstadd_back(t_stack **stack, t_stack *node);
void		ft_lstclean(t_stack **stack);
long		ft_atoi(char *s);
void		ft_lstadd_front(t_stack **stack, t_stack *node);
int			ft_lstsize(t_stack **stack);
