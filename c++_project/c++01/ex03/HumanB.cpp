/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:46:10 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/25 14:24:04 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( void )
{
}

HumanB::HumanB( std::string humanName) : name(humanName)
{
}


HumanB::~HumanB()
{
}

void    HumanB::setWeapon(Weapon& weapon)
{
        this->weapon = &weapon;
}

void    HumanB::attack( void ) const
{
        if (weapon)
                std::cout << name << " attacks with their " << weapon->getType() << std::endl;
        else
                std::cout << name << " There is no weapon " << std::endl;
}
