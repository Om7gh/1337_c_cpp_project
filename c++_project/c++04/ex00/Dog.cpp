/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:12:09 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/30 16:32:29 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void )
{
        type = "Dog";
        std::cout << "Dog constructor is called" << std::endl;
}

Dog::~Dog( void )
{
        std::cout << "Dog destructor is called" << std::endl;
}

void    Dog::makeSound( void ) const
{
        std::cout << "Bard" << std::endl;
}
