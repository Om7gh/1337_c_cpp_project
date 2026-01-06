/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:25:34 by omghazi           #+#    #+#             */
/*   Updated: 2024/11/01 11:12:21 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void )
{
        type = "Unknown type";
        std::cout << "Animal constructor is called" << std::endl;
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
