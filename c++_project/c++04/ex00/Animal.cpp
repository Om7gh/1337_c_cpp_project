/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:25:34 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/30 16:36:00 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void )
{
        type = "Unknown type";
}

Animal::~Animal( void )
{
        std::cout << "Animal destructor is called" << std::endl;
}

std::string    Animal::getType() const
{
        return (type);
}

void    Animal::makeSound( void ) const
{
        std::cout << "Animal sound" << std::endl;
}
