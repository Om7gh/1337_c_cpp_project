/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:28:22 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/21 07:49:46 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
        ScavTrap scav2("Scavvy");
        std::cout << "\n\t\tTesting ScavTrap attack on target 'EnemyBot':\n";
        scav2.bot_attack("EnemyBot");
        std::cout << "\n\t\tTesting ScavTrap taking damage:\n";
        scav2.takeDamage(50);
        scav2.takeDamage(60);
        std::cout << "\n\t\tTesting ScavTrap repair:\n";
        scav2.beRepaired(30);
        std::cout << "\n\t\tTesting ScavTrap in Gate keeper mode:\n";
        scav2.guardGate();
        return (EXIT_SUCCESS);
}
