/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 10:21:43 by omghazi           #+#    #+#             */
/*   Updated: 2024/04/14 11:11:48 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

static int	reverse_rotate(t_stack **stack)
{
	t_stack		*last;
	t_stack		*prev;
	int			size;

	size = ft_lstsize(stack);
	if (size < 2)
		return (0);
	last = *stack;
	prev = NULL;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

int	rra(t_stack **stack)
{
	if (!reverse_rotate(stack))
		return (0);
	return (1);
}

int	rrb(t_stack **stack)
{
	if (!reverse_rotate(stack))
		return (0);
	return (1);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!reverse_rotate(stack_a))
		return (0);
	if (!reverse_rotate(stack_b))
		return (0);
	return (1);
}
