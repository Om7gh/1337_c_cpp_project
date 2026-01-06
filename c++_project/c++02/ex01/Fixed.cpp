/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:49:05 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/29 14:24:41 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

const int Fixed::bit = 8;

Fixed::Fixed( void ) : value(0)
{
        std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed ( const int val )
{
        std::cout << "Int constructor called" << std::endl;
        value = val << bit;
}

Fixed::Fixed ( const float val )
{
        std::cout << "Float constructor called" << std::endl;
        value = roundf(val * (1 << bit));
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

Fixed   &Fixed::operator = ( const Fixed &obj )
{
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &obj)
            this->value = obj.value;
        return (*this);
}

int     Fixed::toInt ( void ) const
{
        return (value >> bit);
}

float   Fixed::toFloat ( void ) const
{
        return static_cast<float>(value) / (1 << bit);
}

std::ostream& operator << (std::ostream &stream, const Fixed &fixed)
{
        stream << fixed.toFloat();
        return (stream);
}
