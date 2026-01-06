/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:32:32 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/31 12:23:24 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{}

ScavTrap::ScavTrap( const std::string name )
{
        this->energy_point = 50;
        this->attack_damage = 20;
        this->hit_point = 100;
        this->name = name;
        std::cout << "\t\t\033[1m\033[37mScavTrap Constructor is called\033[0m" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
        std::cout << "\t\t\033[1m\033[37mScavTrap Destructor is called\033[0m" << std::endl;
}

void    ScavTrap::guardGate( void )
{
        std::cout << "\t\t\033[1m\033[37mScavTrap" << name << "is now in Gate keeper mode.\033[0m" << std::endl;
}

void    ScavTrap::bot_attack( const std::string &target)
{
        if (hit_point <= 0)
        {
                std::cout << "\t\033[1m\033[33m*\033[0mScavTrap " << name << " is \033[1m\033[31mdestroyed\033[0m and can't attack." << std::endl;
                return;
        }
        if (energy_point > 0)
        {
                std::cout << "\t\033[1m\033[33m*\033[0m\t\033[1m\033[37mScavTrap " << name << " \033[36mattacks\033[0m " << target << ", causing " 
                  << attack_damage << " points of damage!\033[0m" << std::endl;
                energy_point--;
        }
        else
        {
                std::cout << "\t\033[1m\033[33m*\033[0m\tScavTrap " << name << " has no energy left for attacking." << std::endl;
                return ;
        }
}
