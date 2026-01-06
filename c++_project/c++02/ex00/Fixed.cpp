/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:17:45 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/29 14:19:22 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bit = 8;

Fixed::Fixed( void ) : value(0)
{
        std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
        std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
        *this = obj;
        std::cout << "Copy Constructor Called" << std::endl;
}

void Fixed::setRawBits( int const raw )
{
        std::cout << "setRawBits member function called" << std::endl;
        this->value = raw;
}

int     Fixed::getRawBits( void ) const
{
        std::cout << "getRawBits member function called" << std::endl;
        return this->value;
}

Fixed   &Fixed::operator = ( const Fixed &obj )
{
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &obj)
            this->value = obj.getRawBits();
        return (*this);
}
