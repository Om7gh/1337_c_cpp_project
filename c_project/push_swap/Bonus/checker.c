/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:14:15 by omghazi           #+#    #+#             */
/*   Updated: 2024/04/15 14:30:58 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static bool	read_actions(t_stack **stack)
{
	char		*rd;
	t_stack		*node;

	rd = get_next_line(0);
	while (rd)
	{
		if (rd == NULL || ft_strcmp(rd, "\4"))
			break ;
		if (ft_strcmp(rd, "pa\n") || ft_strcmp(rd, "pb\n") \
		|| ft_strcmp(rd, "sa\n") || ft_strcmp(rd, "sb\n") \
		|| ft_strcmp(rd, "ss\n") || ft_strcmp(rd, "rra\n") \
		|| ft_strcmp(rd, "rrb\n") || ft_strcmp(rd, "rrr\n") \
		|| ft_strcmp(rd, "ra\n") || ft_strcmp(rd, "rb\n") \
		|| ft_strcmp(rd, "rr\n"))
		{
			node = ft_lstnew_action(rd);
			ft_lstadd_back(stack, node);
		}
		else
			return (ft_lstclean(stack), free(rd), false);
		rd = get_next_line(0);
	}
	free(rd);
	return (true);
}

static void	instruction(t_stack **stack_a, t_stack **stack_b, t_stack *actions)
{
	if (ft_strcmp((actions)->action, "pa\n"))
		pa(stack_a, stack_b);
	else if (ft_strcmp(actions->action, "pb\n"))
		pb(stack_b, stack_a);
	else if (ft_strcmp(actions->action, "sa\n"))
		sa(stack_a);
	else if (ft_strcmp(actions->action, "sb\n"))
		sb(stack_b);
	else if (ft_strcmp(actions->action, "ss\n"))
		ss(stack_a, stack_b);
	else if (ft_strcmp(actions->action, "rra\n"))
		rra(stack_a);
	else if (ft_strcmp(actions->action, "rrb\n"))
		rrb(stack_b);
	else if (ft_strcmp((actions)->action, "rrr\n"))
		rrr(stack_a, stack_b);
	else if (ft_strcmp(actions->action, "ra\n"))
		ra(stack_a);
	else if (ft_strcmp(actions->action, "rb\n"))
		rb(stack_b);
	else if (ft_strcmp(actions->action, "rr\n"))
		rr(stack_a, stack_b);
}

static void	_execute_actions(t_stack **stack_a, \
			t_stack **stack_b, t_stack *actions)
{
	while (actions)
	{
		instruction(stack_a, stack_b, actions);
		actions = actions->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*actions;

	if (ac == 1)
		return (0);
	if (is_empty(av + 1))
		error();
	fill_stack(&stack_a, av + 1);
	if (!read_actions(&actions))
		return (ft_lstclean(&stack_a), ft_putendl("Error"), 1);
	_execute_actions(&stack_a, &stack_b, actions);
	if (!is_sorted(stack_a))
		return (ft_putendl("KO"), \
			mr_propre(&stack_a, &stack_b, &actions, 3), 1);
	else if (is_sorted(stack_a) && !stack_b)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	return (mr_propre(&stack_a, &stack_b, &actions, 3), 0);
}
