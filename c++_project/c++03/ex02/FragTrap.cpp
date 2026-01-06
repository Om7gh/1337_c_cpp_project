/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:11:41 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/21 08:18:26 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{}

FragTrap::FragTrap( const std::string name )
{
        this->energy_point = 100;
        this->attack_damage = 30;
        this->hit_point = 100;
        this->name = name;
        std::cout << "\t\t\033[1m\033[37mFragTrap Constructor is called\033[0m" << std::endl;
}

FragTrap::~FragTrap( void )
{
        std::cout << "\t\t\033[1m\033[37mFragTrap Destructor is called\033[0m" << std::endl;
}

void    FragTrap::highFivesGuys( void )
{
        std::cout << "\t\t\033[1m\033[37mFragTrap " << name << "requests high fives! \033[0m✋" << std::endl;
        return ;
}

void    FragTrap::bot_attack( const std::string &target)
{
         if (hit_point <= 0)
        {
                std::cout << "\t\033[1m\033[33m*\033[0mFragTrap " << name << " is \033[1m\033[31mdestroyed\033[0m and can't attack." << std::endl;
                return;
        }
        if (energy_point > 0)
        {
                std::cout << "\t\033[1m\033[33m*\033[0m\t\033[1m\033[37mFragTrap " << name << " \033[36mattacks\033[0m " << target << ", causing " 
                  << attack_damage << " points of damage!\033[0m" << std::endl;
                energy_point--;
        }
        else
        {
                std::cout << "\t\033[1m\033[33m*\033[0m\tFragTrap " << name << " has no energy left for attacking." << std::endl;
                return ;
        }
}
