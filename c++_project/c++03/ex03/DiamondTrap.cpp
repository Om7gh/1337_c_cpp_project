/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:28:48 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/22 18:07:02 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + " _Clap_name"),  ScavTrap(name), FragTrap(name), _name(name)
{
        hit_point = FragTrap::hit_point;
        attack_damage = FragTrap::attack_damage;
        energy_point = ScavTrap::energy_point;
        std::cout << "\t\tDiamondTrap Constructor is called" << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
        std::cout << "\t\tDiamondTrap Destructor is called" << std::endl;
}

void    DiamondTrap::whoAmI( void )
{
        std::cout << "\t\tDiamondTrap name " << _name << " ClapTrap name " << ClapTrap::name << std::endl;
}
