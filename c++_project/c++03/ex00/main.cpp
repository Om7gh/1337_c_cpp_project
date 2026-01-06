/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 09:57:17 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/19 11:14:49 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
        ClapTrap clappy("omar");

        std::cout << "\t\t\t═══════════════════════════" << std::endl;
        clappy.attack("abdslam");
        clappy.takeDamage(5);
        clappy.beRepaired(3);
        clappy.attack("khalid");
        clappy.takeDamage(8);
        clappy.beRepaired(5);
        std::cout << "\t\t\t═══════════════════════════" << std::endl;
        return (EXIT_SUCCESS);
}
