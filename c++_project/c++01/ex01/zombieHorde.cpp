/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:22:49 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/28 16:20:24 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N < 0)
    {
        std::cout << "number of zombies invalid" << std::endl;
        return (NULL);
    }
    Zombie* horde = new Zombie[N];
    if (!horde)
        return (NULL);
    int i = 0;
    while (i < N)
    {
        new (&horde[i])Zombie(name);
        i++;
    }
    return horde;
}
