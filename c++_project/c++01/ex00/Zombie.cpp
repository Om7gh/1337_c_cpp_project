/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:18:30 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/24 23:59:53 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : name(name){}

Zombie::~Zombie( void )
{
        std::cout << name << " has been destroyed." << std::endl;
}

void    Zombie::announce()
{
        std::cout << Zombie::name << " BraiiiiiiinnnzzzZ... " << std::endl;
}
