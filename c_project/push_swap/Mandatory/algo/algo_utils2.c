/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:28:18 by omghazi           #+#    #+#             */
/*   Updated: 2024/04/04 20:01:40 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	find_min(t_stack **stack)
{
	t_stack	*head;
	int		min;

	min = INT_MAX;
	head = *stack;
	while (head)
	{
		if (head->value < min)
			min = head->value;
		head = head->next;
	}
	return (min);
}

static int	find_next_min(t_stack **stack, int min)
{
	t_stack	*head;
	int		next_min;

	next_min = INT_MAX;
	head = *stack;
	while (head)
	{
		if (head->value < next_min && head->value > min)
			next_min = head->value;
		head = head->next;
	}
	if (next_min == INT_MAX)
		next_min = min;
	return (next_min);
}

static void	index_it(t_stack **stack, int *index, int min)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->value == min)
		{
			tmp->index = *index;
			(*index)++;
		}
		tmp = tmp->next;
	}
}

void	index_stack(t_stack **stack)
{
	t_stack	*head;
	int		min;
	int		i;
	int		size;

	i = 0;
	size = ft_lstsize(stack);
	min = find_min(stack);
	head = *stack;
	while (size > 0)
	{
		index_it(stack, &i, min);
		min = find_next_min(&head, min);
		size --;
	}
}
