/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:14:36 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/30 16:32:16 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void )
{
        type = "Cat";
        std::cout << "Cat constructor is called\n";
}

Cat::~Cat( void )
{
        std::cout << "Cat destructor is called\n";
}

void    Cat::makeSound( void ) const
{
        std::cout << "Meow" << std::endl;
}
