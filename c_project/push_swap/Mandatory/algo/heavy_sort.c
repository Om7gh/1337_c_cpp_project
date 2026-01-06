/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heavy_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:25:14 by omghazi           #+#    #+#             */
/*   Updated: 2024/04/04 20:04:00 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static bool	where_am_i(t_stack **stack, int index)
{
	t_stack	*head;
	int		i;
	int		size;

	head = *stack;
	i = 0;
	size = ft_lstsize(stack);
	while (head && i <= (size / 2))
	{
		if (head->index == index)
			return (true);
		i++;
		head = head->next;
	}
	return (false);
}

void	heavy_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	chunk1;
	int	chunk2;
	int	x;

	chunk2 = 0;
	while (ft_lstsize(stack_a) > 3)
	{
		chunk1 = (ft_lstsize(stack_a) / 6) + chunk2;
		chunk2 += ft_lstsize(stack_a) / 3;
		while (ft_lstsize(stack_b) < chunk2)
		{
			if (*stack_b && (*stack_b)->index < chunk1)
				rb(stack_b);
			if ((*stack_a)->index >= chunk2)
				ra(stack_a);
			else if ((*stack_a)->index < chunk2)
				pb(stack_b, stack_a);
		}
	}
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	x = ft_lstlast((*stack_a))->index;
	push_to_a(stack_a, stack_b, x);
}

void	push_to_a(t_stack **stack_a, t_stack **stack_b, int max)
{
	int	last_in_b;
	int	last_in_a;

	while (*stack_b)
	{
		last_in_a = ft_lstlast(*stack_a)->index;
		last_in_b = ft_lstlast(*stack_b)->index;
		if ((*stack_b)->index == (*stack_a)->index - 1)
			pa(stack_a, stack_b);
		else if ((*stack_a)->index - 1 == last_in_b)
			(rrb(stack_b), pa(stack_a, stack_b));
		else if (last_in_a == max)
			(pa(stack_a, stack_b), ra(stack_a));
		else if (last_in_a == (*stack_a)->index - 1)
			rra(stack_a);
		else if (last_in_a < (*stack_b)->index)
			(pa(stack_a, stack_b), ra(stack_a));
		else if (last_in_a < last_in_b)
			(rrb(stack_b), pa(stack_a, stack_b), ra(stack_a));
		else if (where_am_i(stack_b, (*stack_a)->index - 1))
			rb(stack_b);
		else
			rrb(stack_b);
	}
}
