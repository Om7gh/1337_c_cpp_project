/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:26:47 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/25 11:11:39 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
        Zombie *zombie;
        std::string name;
        int     i;

        i = 5;
        name = "zombie";
        zombie = zombieHorde(i, name);
        if (!zombie)
                return (1);
        i = 0;
        while (i < 5)
        {
                zombie[i].announce();
                i++;
        }
        delete[] zombie;
        return (EXIT_SUCCESS);
}
