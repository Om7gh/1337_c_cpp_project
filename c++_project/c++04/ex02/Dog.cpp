/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:12:09 by omghazi           #+#    #+#             */
/*   Updated: 2024/11/01 11:10:07 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : dogBrain(new Brain())
{
        type = "Dog";
        std::cout << "Dog constructor is called" << std::endl;
}

Dog::~Dog( void )
{
        delete dogBrain;
        dogBrain = NULL;
        std::cout << "Dog destructor is called" << std::endl;
}

Dog::Dog( const Dog &obj) : Animal(obj), dogBrain(new Brain(*obj.dogBrain))
{
        this->type = obj.type;
}

Dog & Dog::operator=( const Dog &obj )
{
        if (this != &obj)
        {
                delete dogBrain;
                dogBrain = new Brain();
                this->type = obj.type;
        }
        return (*this);
}

void    Dog::makeSound( void ) const
{
        std::cout << "Bard" << std::endl;
}
