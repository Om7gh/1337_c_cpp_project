/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:27:58 by omghazi           #+#    #+#             */
/*   Updated: 2024/04/15 14:19:58 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putendl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
	ft_putchar('\n');
}

int	check_value(char c)
{
	return ((c >= '0' && c <= '9') || c == '-' || c == '+');
}

bool	is_valid(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if ((av[i] == '-' || av[i] == '+') && !check_value(av[i + 1]))
			return (false);
		if (!check_value(av[i]))
			return (false);
		if (av[i + 1] == '-' || av[i + 1] == '+')
			return (false);
		i++;
	}
	return (true);
}

bool	is_duplicate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*prev;

	head = *stack;
	while (head)
	{
		prev = head->next;
		while (prev)
		{
			if (head->value == prev->value)
				return (false);
			prev = prev->next;
		}
		head = head->next;
	}
	return (true);
}
