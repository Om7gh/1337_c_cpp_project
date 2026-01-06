/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:41:48 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/09 02:25:33 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "hook_bonus.h"

int	rotate_map(int key, t_env *fdf)
{
	if (key == 84)
	{
		fdf->map->angle->alpha -= 0.04;
		fdf->map->angle->beta -= 0.04;
	}
	else if (key == 85)
	{
		fdf->map->angle->alpha += 0.04;
		fdf->map->angle->beta += 0.04;
	}
	else if (key == 86)
	{
		fdf->map->angle->alpha -= 0.06;
		fdf->map->angle->beta += 0.02;
	}
	else if (key == 87)
	{
		fdf->map->angle->alpha += 0.02;
		fdf->map->angle->beta -= 0.06;
	}
	return (key);
}
