/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:26:29 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/26 20:31:17 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( const std::string& zombieName) : name(zombieName)
{
}

Zombie::Zombie( void )
{
        this->name = "Zombie";
}

Zombie::~Zombie( void )
{
        std::cout << name << " has been destroyed." << std::endl;
}

void    Zombie::announce()
{
        std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
