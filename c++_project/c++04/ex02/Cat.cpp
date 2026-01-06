/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:14:36 by omghazi           #+#    #+#             */
/*   Updated: 2024/11/01 11:09:15 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : catBrain(new Brain())
{
        type = "Cat";
        std::cout << "Cat constructor is called\n";
}

Cat::~Cat( void )
{
        if (catBrain)
                delete catBrain;
        catBrain = NULL;
        std::cout << "Cat destructor is called\n";
}

Cat::Cat( const Cat &obj) : Animal(obj), catBrain(new Brain(*obj.catBrain))
{
        this->type = obj.type;
}

Cat & Cat::operator=( const Cat &obj )
{
        if (this != &obj)
        {
                delete catBrain;
                catBrain = new Brain();
                this->type = obj.type;
        }
        return (*this);
}

void    Cat::makeSound( void ) const
{
        std::cout << "Meow" << std::endl;
}
