/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:03:32 by omghazi           #+#    #+#             */
/*   Updated: 2024/04/05 23:46:21 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

long	ft_atoi(char *s)
{
	int				sign;
	long long		res;
	long long		i;

	sign = 1;
	res = 0;
	i = 0;
	while ((*(s + i) >= 9 && *(s + i) <= 13) || *(s + i) == 32)
		i++;
	if (*(s + i) == '+' || *(s + i) == '-')
	{
		if (*(s + i) == '-')
			sign *= -1;
		i++;
	}
	while (*(s + i) >= '0' && *(s + i) <= '9')
	{
		res = res * 10 + (*(s + i) - '0');
		if (is_overflow(res * sign))
			return (LONG_MAX);
		i++;
	}
	return (res * sign);
}
