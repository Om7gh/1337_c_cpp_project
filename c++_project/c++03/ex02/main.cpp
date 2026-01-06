/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:08:09 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/21 10:22:55 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
        FragTrap frag2("Fraggy");
        std::cout << "\n\t\tTesting FragTrap attack on target 'EnemyBot':\n";
        frag2.attack("EnemyBot");
        std::cout << "\n\t\tTesting FragTrap taking damage:\n";
        frag2.takeDamage(50);
        frag2.takeDamage(60);
        std::cout << "\n\t\tTesting FragTrap repair:\n";
        frag2.beRepaired(30);
        std::cout << "\n\t\tTesting FragTrap high fives:\n";
        frag2.highFivesGuys();
        return (EXIT_SUCCESS);
}
