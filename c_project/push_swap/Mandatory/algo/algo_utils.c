/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 09:32:46 by omghazi           #+#    #+#             */
/*   Updated: 2024/04/14 15:00:41 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	is_sorted(t_stack *stack)
{
	t_stack	*head;
	t_stack	*tmp;

	if (!stack)
		(ft_lstclean(&stack), error());
	head = stack;
	tmp = stack->next;
	while (tmp)
	{
		if (head->value > tmp->value)
			return (false);
		tmp = tmp->next;
		head = head->next;
	}
	return (true);
}

void	max_node(t_stack *stack)
{
	t_stack		*head;
	t_stack		*max;
	int			max_value;

	if (!stack)
		return ;
	head = stack;
	max = NULL;
	max_value = INT_MIN;
	while (head)
	{
		if (head->value > max_value)
		{
			max_value = head->value;
			max = head;
		}
		head = head->next;
	}
	stack->max = max;
}

t_stack	*min_node(t_stack **stack)
{
	t_stack	*head;
	t_stack	*min;

	head = *stack;
	min = head;
	while (head)
	{
		if (head->value < min->value)
			min = head;
		head = head->next;
	}
	return (min);
}

t_stack	*ft_lstlast(t_stack *stack)
{
	t_stack	*last;
	t_stack	*head;

	if (!stack)
		return (NULL);
	head = stack;
	while (head->next)
		head = head->next;
	last = head;
	return (last);
}

void	find_position(t_stack *stack_a)
{
	t_stack	*head;
	int		i;

	head = stack_a;
	i = 0;
	while (head)
	{
		head->position = i;
		i++;
		head = head->next;
	}
}
