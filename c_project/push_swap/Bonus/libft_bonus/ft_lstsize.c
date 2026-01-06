/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:48:29 by omghazi           #+#    #+#             */
/*   Updated: 2024/04/05 23:46:06 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

int	ft_lstsize(t_stack **stack)
{
	t_stack		*head;
	int			size;

	if (!stack || !*stack)
		return (0);
	size = 0;
	head = *stack;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}
