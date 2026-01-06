/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:27:40 by omghazi           #+#    #+#             */
/*   Updated: 2024/04/14 15:15:38 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

bool	is_empty(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j] == ' ' || av[i][j] == '\t')
			j++;
		if (av[i][j] == '\0')
			return (true);
		i++;
	}
	return (false);
}

void	mr_propre(t_stack **a, t_stack **b, t_stack **action, int flag)
{
	if (flag == 1)
		ft_lstclean(a);
	else if (flag == 2)
	{
		ft_lstclean(a);
		ft_lstclean(action);
	}
	else if (flag == 3)
	{
		ft_lstclean(a);
		ft_lstclean(b);
		ft_lstclean(action);
	}
}

bool	is_sorted(t_stack *stack)
{
	t_stack	*head;
	t_stack	*actions;

	if (!stack)
		return (ft_lstclean(&stack), (true));
	head = stack;
	actions = stack->next;
	while (actions)
	{
		if (head->value > actions->value)
			return (false);
		actions = actions->next;
		head = head->next;
	}
	return (true);
}
