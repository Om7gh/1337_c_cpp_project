/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:25:08 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/21 10:32:52 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
}

ClapTrap::ClapTrap( std::string name ) : name(name) , hit_point(10), energy_point(10), attack_damage(0)
{
        std::cout << "\t\033[1m\033[33m*\033[0m\t\033[1m\033[33mConstructor is called !\033[0m" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
        std::cout << "\t\033[1m\033[33m*\033[0m\t\033[1m\033[33mDestructor is called !\033[0m" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
        if (hit_point <= 0)
        {
                std::cout << "\t\033[1m\033[33m*\033[0m\tClapTrap " << name << " is \033[1m\033[31mdestroyed\033[0m and can't attack." << std::endl;
                return;
        }
        if (energy_point > 0)
        {
                std::cout << "\t\033[1m\033[33m*\033[0m\t\033[1m\033[37mClapTrap " << name << " \033[36mattacks\033[0m " << target << ", causing " 
                  << attack_damage << " points of damage!\033[0m" << std::endl;
                energy_point--;
        }
        else
                std::cout << "\t\033[1m\033[33m*\033[0m\tClapTrap " << name << " has no energy left for attacking." << std::endl;
}
void    ClapTrap::takeDamage(unsigned int amount)
{
        if (hit_point > 0)
        {
                if (amount >= hit_point)
                        hit_point = 0;
                else
                        hit_point -= amount;
                std::cout << "\t\033[1m\033[33m*\033[0m\t\033[1m\033[37mClapTrap " << name << " takes " << amount << " points of damage.\033[0m" << std::endl;
                if (hit_point <= 0)
                {
                        hit_point = 0;
                        std::cout << "\t\033[1m\033[33m*\033[0m\t\033[1m\033[37mlapTrap " << name << " has 0 hit points left.\033[0m" << std::endl;
                        std::cout << "\t\033[1m\033[33m*\033[0m\t\033[1m\033[37mClapTrap " << name << " is \033[1m\033[31mdestroyed\033[0m!\033[0m" << std::endl;
                }
                else
                        std::cout << "\t\033[1m\033[33m*\033[0m\t\033[1m\033[37mClapTrap " << name << " has " << hit_point << " hit points left.\033[0m" << std::endl;
        }
        else
                std::cout << "\t\033[1m\033[33m*\033[0m\tClapTrap " << name << " is already \033[1m\033[31mdestroyed\033[0m!" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
        if (hit_point <= 0)
        {
                std::cout << "\t\033[1m\033[33m*\033[0m\t\033[1m\033[37mClapTrap " << name << " is \033[1m\033[31mdestroyed\033[0m and can't repair itself.\033[0m" << std::endl;
                return;
        }
        if (energy_point > 0)
        {
                hit_point += amount;
                energy_point--;
                std::cout << "\t\033[1m\033[33m*\033[0m\t\033[1m\033[37mClapTrap " << name << " repairs itself, recovering " 
                        << amount << " hit points!\033[0m" << std::endl;
        }
        else
                std::cout << "\t\033[1m\033[33m*\033[0m\t\033[1m\033[37mClapTrap " << name << " has no energy left for repairing\033[0m." << std::endl;
}
