/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:37:26 by omghazi           #+#    #+#             */
/*   Updated: 2024/04/05 14:15:03 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*head;
	t_stack	*max;

	max_node(*stack);
	head = *stack;
	max = head->max;
	if (max->value == head->value)
	{
		if (head->next->value > head->next->next->value)
			(sa(stack), rra(stack));
		else
			ra(stack);
	}
	else if (max->value == head->next->value)
	{
		if (head->value > head->next->next->value)
			rra(stack);
		else
			(rra(stack), sa(stack));
	}
	else
	{
		if (head->value > head->next->value)
			sa(stack);
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;

	find_position(*stack_a);
	min = min_node(stack_a);
	if ((*stack_a)->value != min->value)
	{
		while (min->position)
		{
			if (min->position <= ft_lstsize(stack_a) / 2)
			{
				if (!ra(stack_a))
					return ;
			}
			else
				if (!rra(stack_a))
					return ;
			find_position(*stack_a);
		}
	}
	if (!pb(stack_b, stack_a))
		return ;
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	if (!pa(stack_a, stack_b))
		return ;
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;

	find_position(*stack_a);
	min = min_node(stack_a);
	if ((*stack_a)->value != min->value)
	{
		while (min->position)
		{
			if (min->position <= ft_lstsize(stack_a) / 2)
			{
				if (!ra(stack_a))
					return ;
			}
			else
				if (!rra(stack_a))
					return ;
			find_position(*stack_a);
		}
	}
	if (!pb(stack_b, stack_a))
		return ;
	if (!is_sorted(*stack_a))
		sort_four(stack_a, stack_b);
	if (!pa(stack_a, stack_b))
		return ;
}
