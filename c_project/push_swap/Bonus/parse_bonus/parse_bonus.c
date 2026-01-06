/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:19:34 by omghazi           #+#    #+#             */
/*   Updated: 2024/04/14 14:40:39 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

static int	push_and_check(t_stack **stack, char **tmp, int j)
{
	t_stack	*node;

	while (tmp[++j])
	{
		if (!is_valid(tmp[j]))
			error();
		if (ft_atoi(tmp[j]) == LONG_MAX)
			(free_2d(tmp, j), ft_lstclean(stack), error());
		node = ft_lstnew(ft_atoi(tmp[j]));
		if (!node)
		{
			(free_2d(tmp, j), ft_lstclean(stack));
			return (0);
		}
		ft_lstadd_back(stack, node);
		if (!is_duplicate(stack))
			(ft_lstclean(stack), error());
		free(tmp[j]);
	}
	free(tmp);
	return (1);
}

void	fill_stack(t_stack **stack, char **av)
{
	char		**tmp;
	int			i;
	long		j;

	i = -1;
	while (av[++i])
	{
		tmp = ft_split(av[i]);
		if (!tmp)
		{
			free_2d(av, i);
			ft_lstclean(stack);
			error();
		}
		j = -1;
		if (!push_and_check(stack, tmp, j))
			(ft_lstclean(stack), error());
	}
}
