/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 10:21:47 by omghazi           #+#    #+#             */
/*   Updated: 2024/04/15 14:32:29 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	if (ft_lstsize(stack) < 2 || !stack || !*stack)
		return (0);
	head = *stack;
	*stack = head->next;
	last = head;
	while (last->next)
		last = last->next;
	head->next = NULL;
	last->next = head;
	return (1);
}

int	ra(t_stack **stack)
{
	if (!rotate(stack))
		return (0);
	ft_putendl("ra");
	return (1);
}

int	rb(t_stack **stack)
{
	if (!rotate(stack))
		return (0);
	ft_putendl("rb");
	return (1);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!rotate(stack_a))
		return (0);
	if (!rotate(stack_b))
		return (0);
	ft_putendl("rr");
	return (1);
}
