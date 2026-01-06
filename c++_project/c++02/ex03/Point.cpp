/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:58:52 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/29 18:41:14 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point ( void ) : x(Fixed(0)), y(Fixed(0))
{}

Point::Point ( const float x, const float y ) : x(Fixed(x)), y(Fixed(y))
{}

Point::Point ( const Point &obj ) : x(Fixed(obj.getX())), y(Fixed(obj.getY()))
{}

Point::~Point ( void )
{}

Point & Point::operator=(const Point &obj)
{
        if (this != &obj)
                *this = obj;
        return (*this);
}
