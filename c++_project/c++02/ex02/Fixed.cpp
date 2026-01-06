/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:17:10 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/10 22:36:32 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int       Fixed::fractionalBits = 8;

Fixed::Fixed( void ) : value(0)
{
}

Fixed::Fixed ( const int val )
{
        this->value = val << fractionalBits;
}

Fixed::Fixed ( const float val )
{
        this->value = static_cast<int>(roundf(val * (1 << fractionalBits)));
}

Fixed::~Fixed( void )
{
}

Fixed::Fixed(const Fixed &obj)
{
        this->value = obj.value;
}

Fixed   &Fixed::operator = ( const Fixed &obj )
{
        if (this != &obj)
            this->value = obj.value;
        return (*this);
}

int     Fixed::toInt ( void ) const
{
        return (this->value >> fractionalBits);
}

float   Fixed::toFloat ( void ) const
{
        return static_cast<float>(this->value) / (1 << fractionalBits);
}

bool Fixed::operator>(const Fixed& other) const
{
    return this->value > other.value;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->value != other.value;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.value = this->value + other.value;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.value = this->value - other.value;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    result.value = (this->value * other.value) >> fractionalBits;
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    result.value = (this->value << fractionalBits) / other.value;
    return result;
}

Fixed& Fixed::operator++()
{
    this->value += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->value += 1;
    return temp;
}

Fixed& Fixed::operator--()
{
    this->value -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->value -= 1;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed)
{
    stream << fixed.toFloat();
    return stream;
}
